$NetBSD: patch-src_cpu.c,v 1.4 2020/10/24 22:39:45 wiz Exp $

Port this too to NetBSD.

--- src/cpu.c.orig	2020-03-08 16:57:09.000000000 +0100
+++ src/cpu.c	2020-07-07 12:08:28.927383000 +0200
@@ -78,13 +78,16 @@
 #endif
 #endif /* HAVE_SYS_DKSTAT_H */
 
-#define CAN_USE_SYSCTL 0
 #if (defined(HAVE_SYSCTL) && defined(HAVE_SYSCTLBYNAME)) || defined(__OpenBSD__)
 /* Implies BSD variant */
 #if defined(CTL_HW) && defined(HW_NCPU) && defined(CTL_KERN) &&                \
-    defined(KERN_CPTIME) && defined(CPUSTATES)
+    (defined(KERN_CPTIME) || defined(KERN_CP_TIME)) && defined(CPUSTATES)
 #define CAN_USE_SYSCTL 1
+#else
+#define CAN_USE_SYSCTL 0
 #endif
+#else
+#define CAN_USE_SYSCTL 0
 #endif /* HAVE_SYSCTL_H && HAVE_SYSCTLBYNAME || __OpenBSD__ */
 
 #define COLLECTD_CPU_STATE_USER 0
@@ -746,6 +749,24 @@ static int cpu_read(void) {
 
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
@@ -779,6 +800,7 @@ static int cpu_read(void) {
       cpuinfo[0][i] = cpuinfo_tmp[i];
     }
   }
+#endif /* defined(KERN_CP_TIME) && defined(KERNEL_NETBSD) */
 
   for (int i = 0; i < numcpu; i++) {
     cpu_stage(i, COLLECTD_CPU_STATE_USER, (derive_t)cpuinfo[i][CP_USER], now);
