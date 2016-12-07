$NetBSD: patch-src_cpu.c,v 1.3 2016/12/07 17:28:39 fhajny Exp $

Port this too to NetBSD.

--- src/cpu.c.orig	2016-11-30 08:52:01.308911943 +0000
+++ src/cpu.c
@@ -81,7 +81,7 @@
 
 #if HAVE_SYSCTL
 #if defined(CTL_HW) && defined(HW_NCPU) && defined(CTL_KERN) &&                \
-    defined(KERN_CPTIME) && defined(CPUSTATES)
+    (defined(KERN_CPTIME) || defined(KERN_CP_TIME)) && defined(CPUSTATES)
 #define CAN_USE_SYSCTL 1
 #else
 #define CAN_USE_SYSCTL 0
@@ -673,6 +673,24 @@ static int cpu_read(void) {
 
   memset(cpuinfo, 0, sizeof(cpuinfo));
 
+#if defined(KERN_CP_TIME) && defined(KERNEL_NETBSD)
+  {
+    int mib[] = {CTL_KERN, KERN_CP_TIME};
+
+    cpuinfo_size = sizeof(cpuinfo[0]) * numcpu * CPUSTATES;
+    status = sysctl(mib, 2, cpuinfo, &cpuinfo_size, NULL, 0);
+    if (status == -1) {
+      char errbuf[1024];
+
+      ERROR ("cpu plugin: sysctl failed: %s.",
+             sstrerror (errno, errbuf, sizeof (errbuf)));
+      return -1;
+    }
+    if (cpuinfo_size == (sizeof(cpuinfo[0]) * CPUSTATES)) {
+      numcpu = 1;
+    }
+  }
+#else /* defined(KERN_CP_TIME) && defined(KERNEL_NETBSD) */
 #if defined(KERN_CPTIME2)
   if (numcpu > 1) {
     for (int i = 0; i < numcpu; i++) {
@@ -710,6 +728,7 @@ static int cpu_read(void) {
       cpuinfo[0][i] = cpuinfo_tmp[i];
     }
   }
+#endif /* defined(KERN_CP_TIME) && defined(KERNEL_NETBSD) */
 
   for (int i = 0; i < numcpu; i++) {
     cpu_stage(i, COLLECTD_CPU_STATE_USER, (derive_t)cpuinfo[i][CP_USER], now);
