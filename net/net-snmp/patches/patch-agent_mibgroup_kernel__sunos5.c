$NetBSD: patch-agent_mibgroup_kernel__sunos5.c,v 1.1 2015/08/20 13:51:03 jperkin Exp $

Support Crossbow.

--- agent/mibgroup/kernel_sunos5.c.orig	2014-12-08 20:23:22.000000000 +0000
+++ agent/mibgroup/kernel_sunos5.c
@@ -291,8 +291,8 @@ init_kernel_sunos5(void)
 
 
 int
-getKstatInt(const char *classname, const char *statname, 
-	    const char *varname, int *value)
+getKstatInt(char *classname, char *statname,
+               char *varname, int *value)
 {
     kstat_ctl_t    *ksc;
     kstat_t        *ks;
@@ -373,7 +373,7 @@ getKstatInt(const char *classname, const
 }
 
 int
-getKstat(const char *statname, const char *varname, void *value)
+getKstat(char *statname, char *varname, void *value)
 {
     kstat_ctl_t    *ksc;
     kstat_t        *ks, *kstat_data;
@@ -537,7 +537,7 @@ getKstat(const char *statname, const cha
 }
 
 int
-getKstatString(const char *statname, const char *varname,
+getKstatString(char *statname, char *varname,
                char *value, size_t value_len)
 {
     kstat_ctl_t    *ksc;
@@ -1642,9 +1642,9 @@ set_if_info(mib2_ifEntry_t *ifp, unsigne
     ifp->ifSpeed = 0;
 
     /*
-     * Get link speed
+     * Get link speed, try the "link" module first, then fallback to NULL (ie: unix)
      */
-    if ((getKstatInt(NULL, name, "ifspeed", &ifp->ifSpeed) == 0)) {
+    if ((getKstatInt("link", name, "ifspeed", &ifp->ifSpeed) == 0)) {
         /*
          * check for SunOS patch with half implemented ifSpeed 
          */
@@ -1652,7 +1652,10 @@ set_if_info(mib2_ifEntry_t *ifp, unsigne
             ifp->ifSpeed *= 1000000;
         }
 	havespeed = B_TRUE;
-    } else if (getKstatInt(NULL, name, "ifSpeed", &ifp->ifSpeed) == 0) {
+	/* WORKAROUND: If this is a link and DLPI doesn't know, its probly a VNIC */
+	if (ifp->ifType == 1 || ifp->ifType == 0)
+		ifp->ifType = 6;
+    } else if (getKstatInt(NULL, name, "ifspeed", &ifp->ifSpeed) == 0) {
         /*
          * this is good 
          */
@@ -1683,6 +1686,9 @@ set_if_info(mib2_ifEntry_t *ifp, unsigne
 
     /*
      * Set link Type and Speed (if it could not be determined from kstat)
+     *
+     * NOTE: This whole method makes no sense in a world of Vanity Names,
+     *              and should be completely revised. - benr
      */
     if (ifp->ifType == 24) {
         ifp->ifSpeed = 127000000;
@@ -1765,15 +1771,31 @@ get_if_stats(mib2_ifEntry_t *ifp)
 {
     Counter l_tmp;
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
+    if (getKstatInt(classname, name, "ipackets64", &ifp->ifHCInUcastPkts) != 0) {
         if (getKstatInt(NULL, name, "ipackets", &ifp->ifInUcastPkts) != 0) {
             return (-1);
         }
@@ -1781,7 +1803,7 @@ get_if_stats(mib2_ifEntry_t *ifp)
             ifp->ifInUcastPkts = (uint32_t)(ifp->ifHCInUcastPkts & 0xffffffff); 
     }
     
-    if (getKstat(name, "rbytes64", &ifp->ifHCInOctets) != 0) {
+    if (getKstatInt(classname, name, "rbytes64", &ifp->ifHCInOctets) != 0) {
         if (getKstatInt(NULL, name, "rbytes", &ifp->ifInOctets) != 0) {
             ifp->ifInOctets = ifp->ifInUcastPkts * 308; 
         }
@@ -1789,7 +1811,7 @@ get_if_stats(mib2_ifEntry_t *ifp)
             ifp->ifInOctets = (uint32_t)(ifp->ifHCInOctets & 0xffffffff);
     }
    
-    if (getKstat(name, "opackets64", &ifp->ifHCOutUcastPkts) != 0) {
+    if (getKstatInt(classname, name, "opackets64", &ifp->ifHCOutUcastPkts) != 0) {
         if (getKstatInt(NULL, name, "opackets", &ifp->ifOutUcastPkts) != 0) {
             return (-1);
         }
@@ -1797,7 +1819,7 @@ get_if_stats(mib2_ifEntry_t *ifp)
          ifp->ifOutUcastPkts = (uint32_t)(ifp->ifHCOutUcastPkts & 0xffffffff);
     }
     
-    if (getKstat(name, "obytes64", &ifp->ifHCOutOctets) != 0) {
+    if (getKstatInt(classname, name, "obytes64", &ifp->ifHCOutOctets) != 0) {
         if (getKstatInt(NULL, name, "obytes", &ifp->ifOutOctets) != 0) { 
             ifp->ifOutOctets = ifp->ifOutUcastPkts * 308;    /* XXX */
         }
@@ -1809,31 +1831,31 @@ get_if_stats(mib2_ifEntry_t *ifp)
         return (0);
 
     /* some? VLAN interfaces don't have error counters, so ignore failure */
-    getKstatInt(NULL, name, "ierrors", &ifp->ifInErrors);
-    getKstatInt(NULL, name, "oerrors", &ifp->ifOutErrors);
+    getKstatInt(classname, name, "ierrors", &ifp->ifInErrors);
+    getKstatInt(classname, name, "oerrors", &ifp->ifOutErrors);
 
     /* Try to grab some additional information */
-    getKstatInt(NULL, name, "collisions", &ifp->ifCollisions); 
-    getKstatInt(NULL, name, "unknowns", &ifp->ifInUnknownProtos); 
+    getKstatInt(classname, name, "collisions", &ifp->ifCollisions);
+    getKstatInt(classname, name, "unknowns", &ifp->ifInUnknownProtos);
                 
 
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
