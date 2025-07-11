$NetBSD: patch-agent_mibgroup_kernel__sunos5.c,v 1.3 2025/07/11 10:11:52 jperkin Exp $

Support Crossbow.
Integer conversion fixes.

--- agent/mibgroup/kernel_sunos5.c.orig	2023-08-15 20:32:01.000000000 +0000
+++ agent/mibgroup/kernel_sunos5.c
@@ -285,8 +285,8 @@ init_kernel_sunos5(void)
 
 
 int
-getKstatInt(const char *classname, const char *statname, 
-	    const char *varname, int *value)
+getKstatInt(char *classname, char *statname,
+               char *varname, uintptr_t *value)
 {
     kstat_ctl_t    *ksc;
     kstat_t        *ks;
@@ -368,7 +368,7 @@ getKstatInt(const char *classname, const
 }
 
 int
-getKstat(const char *statname, const char *varname, void *value)
+getKstat(char *statname, char *varname, void *value)
 {
     kstat_ctl_t    *ksc;
     kstat_t        *ks, *kstat_data;
@@ -534,7 +534,7 @@ getKstat(const char *statname, const cha
 }
 
 int
-getKstatString(const char *statname, const char *varname,
+getKstatString(char *statname, char *varname,
                char *value, size_t value_len)
 {
     kstat_ctl_t    *ksc;
@@ -1643,9 +1643,9 @@ set_if_info(mib2_ifEntry_t *ifp, unsigne
     ifp->ifHighSpeed = 0;
 
     /*
-     * Get link speed
+     * Get link speed, try the "link" module first, then fallback to NULL (ie: unix)
      */
-    if ((getKstat(name, "ifspeed", &ifspeed) == 0)) {
+    if ((getKstatInt("link", name, "ifspeed", (uintptr_t *)&ifp->ifSpeed) == 0)) {
         /*
          * check for SunOS patch with half implemented ifSpeed 
          */
@@ -1653,7 +1653,10 @@ set_if_info(mib2_ifEntry_t *ifp, unsigne
             ifspeed *= 1000000;
         }
 	havespeed = B_TRUE;
-    } else if (getKstat(name, "ifSpeed", &ifspeed) == 0) {
+	/* WORKAROUND: If this is a link and DLPI doesn't know, its probly a VNIC */
+	if (ifp->ifType == 1 || ifp->ifType == 0)
+		ifp->ifType = 6;
+    } else if (getKstatInt(NULL, name, "ifspeed", (uintptr_t *)&ifp->ifSpeed) == 0) {
         /*
          * this is good 
          */
@@ -1669,7 +1672,7 @@ set_if_info(mib2_ifEntry_t *ifp, unsigne
 
     /* make ifOperStatus depend on link status if available */
     if (ifp->ifAdminStatus == 1) {
-        int i_tmp;
+        uintptr_t i_tmp;
         /* only UPed interfaces get correct link status - if any */
         if (getKstatInt(NULL, name,"link_up",&i_tmp) == 0) {
             ifp->ifOperStatus = i_tmp ? 1 : 2;
@@ -1689,6 +1692,9 @@ set_if_info(mib2_ifEntry_t *ifp, unsigne
 
     /*
      * Set link Type and Speed (if it could not be determined from kstat)
+     *
+     * NOTE: This whole method makes no sense in a world of Vanity Names,
+     *              and should be completely revised. - benr
      */
     if (ifp->ifType == 24) {
         ifp->ifSpeed = 127000000;
@@ -1769,42 +1775,58 @@ set_if_info(mib2_ifEntry_t *ifp, unsigne
 static int 
 get_if_stats(mib2_ifEntry_t *ifp)
 {
-    int l_tmp;
+    uintptr_t l_tmp;
     char *name = ifp->ifDescr.o_bytes;
+    char classname[32];
 
     if (strchr(name, ':'))
         return (0); 
 
     /*
+       Added by <benr@joyent.com> on 6/24/11
+       getKstat() calls replaced by getKstatInt with proper class
+       if not present, unix class is used which are 0 values in
+       a Crossbow (VNIC) world.
+
+       FIXME: Should revert to NULL classname if we're on an old release.
+
+    */
+    if (strncmp(name, "lo", 2) == 0) {
+       strcpy(classname, "lo");
+    } else {
+       strcpy(classname, "link");
+    }
+
+    /*
      * First try to grab 64-bit counters; if they are not available,
      * fall back to 32-bit.
      */
-    if (getKstat(name, "ipackets64", &ifp->ifHCInUcastPkts) != 0) {
-        if (getKstatInt(NULL, name, "ipackets", &ifp->ifInUcastPkts) != 0) {
+    if (getKstatInt(classname, name, "ipackets64", (uintptr_t *)&ifp->ifHCInUcastPkts) != 0) {
+        if (getKstatInt(NULL, name, "ipackets", (uintptr_t *)&ifp->ifInUcastPkts) != 0) {
             return (-1);
         }
     } else { 
             ifp->ifInUcastPkts = (uint32_t)(ifp->ifHCInUcastPkts & 0xffffffff); 
     }
     
-    if (getKstat(name, "rbytes64", &ifp->ifHCInOctets) != 0) {
-        if (getKstatInt(NULL, name, "rbytes", &ifp->ifInOctets) != 0) {
+    if (getKstatInt(classname, name, "rbytes64", (uintptr_t *)&ifp->ifHCInOctets) != 0) {
+        if (getKstatInt(NULL, name, "rbytes", (uintptr_t *)&ifp->ifInOctets) != 0) {
             ifp->ifInOctets = ifp->ifInUcastPkts * 308; 
         }
     } else {
             ifp->ifInOctets = (uint32_t)(ifp->ifHCInOctets & 0xffffffff);
     }
    
-    if (getKstat(name, "opackets64", &ifp->ifHCOutUcastPkts) != 0) {
-        if (getKstatInt(NULL, name, "opackets", &ifp->ifOutUcastPkts) != 0) {
+    if (getKstatInt(classname, name, "opackets64", (uintptr_t *)&ifp->ifHCOutUcastPkts) != 0) {
+        if (getKstatInt(NULL, name, "opackets", (uintptr_t *)&ifp->ifOutUcastPkts) != 0) {
             return (-1);
         }
     } else {
          ifp->ifOutUcastPkts = (uint32_t)(ifp->ifHCOutUcastPkts & 0xffffffff);
     }
     
-    if (getKstat(name, "obytes64", &ifp->ifHCOutOctets) != 0) {
-        if (getKstatInt(NULL, name, "obytes", &ifp->ifOutOctets) != 0) { 
+    if (getKstatInt(classname, name, "obytes64", (uintptr_t *)&ifp->ifHCOutOctets) != 0) {
+        if (getKstatInt(NULL, name, "obytes", (uintptr_t *)&ifp->ifOutOctets) != 0) { 
             ifp->ifOutOctets = ifp->ifOutUcastPkts * 308;    /* XXX */
         }
     } else {
@@ -1815,31 +1837,31 @@ get_if_stats(mib2_ifEntry_t *ifp)
         return (0);
 
     /* some? VLAN interfaces don't have error counters, so ignore failure */
-    getKstatInt(NULL, name, "ierrors", &ifp->ifInErrors);
-    getKstatInt(NULL, name, "oerrors", &ifp->ifOutErrors);
+    getKstatInt(classname, name, "ierrors", (uintptr_t *)&ifp->ifInErrors);
+    getKstatInt(classname, name, "oerrors", (uintptr_t *)&ifp->ifOutErrors);
 
     /* Try to grab some additional information */
-    getKstatInt(NULL, name, "collisions", &ifp->ifCollisions); 
-    getKstatInt(NULL, name, "unknowns", &ifp->ifInUnknownProtos); 
+    getKstatInt(classname, name, "collisions", (uintptr_t *)&ifp->ifCollisions);
+    getKstatInt(classname, name, "unknowns", (uintptr_t *)&ifp->ifInUnknownProtos);
                 
 
     /*
      * TODO some NICs maintain 64-bit counters for multi/broadcast
      * packets; should try to get that information.
      */
-    if (getKstatInt(NULL, name, "brdcstrcv", &l_tmp) == 0) 
+    if (getKstatInt(classname, name, "brdcstrcv", &l_tmp) == 0)
         ifp->ifHCInBroadcastPkts = l_tmp;
 
-    if (getKstatInt(NULL, name, "multircv", &l_tmp) == 0)
+    if (getKstatInt(classname, name, "multircv", &l_tmp) == 0)
         ifp->ifHCInMulticastPkts = l_tmp;
 
     ifp->ifInNUcastPkts = (uint32_t)(ifp->ifHCInBroadcastPkts + 
                                      ifp->ifHCInMulticastPkts);
 
-    if (getKstatInt(NULL, name, "brdcstxmt", &l_tmp) == 0)
+    if (getKstatInt(classname, name, "brdcstxmt", &l_tmp) == 0)
         ifp->ifHCOutBroadcastPkts = l_tmp;
 
-    if (getKstatInt(NULL, name, "multixmt", &l_tmp) == 0)
+    if (getKstatInt(classname, name, "multixmt", &l_tmp) == 0)
         ifp->ifHCOutMulticastPkts = l_tmp;
 
     ifp->ifOutNUcastPkts = (uint32_t)(ifp->ifHCOutBroadcastPkts + 
