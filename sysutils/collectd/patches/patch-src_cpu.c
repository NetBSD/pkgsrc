$NetBSD: patch-src_cpu.c,v 1.1 2015/08/26 12:19:27 he Exp $

Port this too to NetBSD.

--- src/cpu.c.orig	2015-03-10 14:14:45.000000000 +0000
+++ src/cpu.c
@@ -79,7 +79,9 @@
 
 #if HAVE_SYSCTL
 # if defined(CTL_HW) && defined(HW_NCPU) \
-	&& defined(CTL_KERN) && defined(KERN_CPTIME) && defined(CPUSTATES)
+	&& defined(CTL_KERN) \
+	&& (defined(KERN_CPTIME) || defined(KERN_CP_TIME)) \
+	&& defined(CPUSTATES)
 #  define CAN_USE_SYSCTL 1
 # else
 #  define CAN_USE_SYSCTL 0
@@ -676,6 +678,24 @@ static int cpu_read (void)
 
 	memset (cpuinfo, 0, sizeof (cpuinfo));
 
+#if defined(KERN_CP_TIME) && defined(KERNEL_NETBSD)
+	{
+		int mib[] = {CTL_KERN, KERN_CP_TIME};
+
+		cpuinfo_size = sizeof(cpuinfo[0]) * numcpu * CPUSTATES;
+		status = sysctl(mib, 2, cpuinfo, &cpuinfo_size, NULL, 0);
+		if (status == -1) {
+			char errbuf[1024];
+
+			ERROR ("cpu plugin: sysctl failed: %s.",
+			       sstrerror (errno, errbuf, sizeof (errbuf)));
+			return -1;
+		}
+		if (cpuinfo_size == (sizeof(cpuinfo[0]) * CPUSTATES)) {
+			numcpu = 1;
+		}
+	}
+#else /* defined(KERN_CP_TIME) && defined(KERNEL_NETBSD) */
 #if defined(KERN_CPTIME2)
 	if (numcpu > 1) {
 		for (i = 0; i < numcpu; i++) {
@@ -715,6 +735,7 @@ static int cpu_read (void)
 			cpuinfo[0][i] = cpuinfo_tmp[i];
 		}
 	}
+#endif /* defined(KERN_CP_TIME) && defined(KERNEL_NETBSD) */
 
 	for (i = 0; i < numcpu; i++) {
 		cpu_stage (i, COLLECTD_CPU_STATE_USER,      (derive_t) cpuinfo[i][CP_USER], now);
