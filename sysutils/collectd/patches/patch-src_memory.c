$NetBSD: patch-src_memory.c,v 1.1 2015/08/11 13:19:21 he Exp $

Add a port for NetBSD using VM_UVMEXP2, and preferring
sysctl over sysctlbyname.

--- src/memory.c.orig	2015-03-10 14:14:45.000000000 +0000
+++ src/memory.c
@@ -65,6 +65,10 @@ static mach_port_t port_host;
 static vm_size_t pagesize;
 /* #endif HAVE_HOST_STATISTICS */
 
+#elif HAVE_SYSCTL
+static int pagesize;
+/* #endif HAVE_SYSCTL */
+
 #elif HAVE_SYSCTLBYNAME
 /* no global variables */
 /* #endif HAVE_SYSCTLBYNAME */
@@ -78,10 +82,6 @@ static int pagesize;
 static kstat_t *ksp;
 /* #endif HAVE_LIBKSTAT */
 
-#elif HAVE_SYSCTL
-static int pagesize;
-/* #endif HAVE_SYSCTL */
-
 #elif HAVE_LIBSTATGRAB
 /* no global variables */
 /* endif HAVE_LIBSTATGRAB */
@@ -121,6 +121,15 @@ static int memory_init (void)
 	host_page_size (port_host, &pagesize);
 /* #endif HAVE_HOST_STATISTICS */
 
+#elif HAVE_SYSCTL
+	pagesize = getpagesize ();
+	if (pagesize <= 0)
+	{
+		ERROR ("memory plugin: Invalid pagesize: %i", pagesize);
+		return (-1);
+	}
+/* #endif HAVE_SYSCTL */
+
 #elif HAVE_SYSCTLBYNAME
 /* no init stuff */
 /* #endif HAVE_SYSCTLBYNAME */
@@ -139,15 +148,6 @@ static int memory_init (void)
 	}
 /* #endif HAVE_LIBKSTAT */
 
-#elif HAVE_SYSCTL
-	pagesize = getpagesize ();
-	if (pagesize <= 0)
-	{
-		ERROR ("memory plugin: Invalid pagesize: %i", pagesize);
-		return (-1);
-	}
-/* #endif HAVE_SYSCTL */
-
 #elif HAVE_LIBSTATGRAB
 /* no init stuff */
 /* #endif HAVE_LIBSTATGRAB */
@@ -221,6 +221,46 @@ static int memory_read_internal (value_l
 /* #endif HAVE_HOST_STATISTICS */
 
 #elif HAVE_SYSCTLBYNAME
+
+#if HAVE_SYSCTL && defined(KERNEL_NETBSD)
+	int mib[] = {CTL_VM, VM_UVMEXP2};
+	struct uvmexp_sysctl uvmexp;
+	gauge_t mem_active;
+	gauge_t mem_inactive;
+	gauge_t mem_free;
+	gauge_t mem_wired;
+	gauge_t mem_kernel;
+	size_t size;
+
+	memset (&uvmexp, 0, sizeof (uvmexp));
+	size = sizeof (uvmexp);
+
+	if (sysctl (mib, 2, &uvmexp, &size, NULL, 0) < 0) {
+		char errbuf[1024];
+		WARNING ("memory plugin: sysctl failed: %s",
+			sstrerror (errno, errbuf, sizeof (errbuf)));
+		return (-1);
+	}
+
+	assert (pagesize > 0);
+	mem_active   = (gauge_t) (uvmexp.active * pagesize);
+	mem_inactive = (gauge_t) (uvmexp.inactive * pagesize);
+	mem_free     = (gauge_t) (uvmexp.free * pagesize);
+	mem_wired    = (gauge_t) (uvmexp.wired * pagesize);
+	mem_kernel   = (gauge_t) ((uvmexp.npages - (
+					uvmexp.active + uvmexp.inactive +
+					uvmexp.free + uvmexp.wired
+					)) * pagesize);
+
+	MEMORY_SUBMIT ("active",   mem_active,
+	               "inactive", mem_inactive,
+	               "free",     mem_free,
+	               "wired",    mem_wired,
+	               "kernel",   mem_kernel);
+/* #endif HAVE_SYSCTL && defined(KERNEL_NETBSD) */
+
+#else /* Other HAVE_SYSCTLBYNAME providers */
+
 	/*
 	 * vm.stats.vm.v_page_size: 4096
 	 * vm.stats.vm.v_page_count: 246178
@@ -272,6 +312,8 @@ static int memory_read_internal (value_l
 	               "active",   (gauge_t) sysctl_vals[4],
 	               "inactive", (gauge_t) sysctl_vals[5],
 	               "cache",    (gauge_t) sysctl_vals[6]);
+
+#endif /* HAVE_SYSCTL && KERNEL_NETBSD */
 /* #endif HAVE_SYSCTLBYNAME */
 
 #elif KERNEL_LINUX
