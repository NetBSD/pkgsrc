$NetBSD: patch-src_memory.c,v 1.6 2020/10/24 22:39:45 wiz Exp $

Add a port for NetBSD using VM_UVMEXP2, and preferring
sysctl over sysctlbyname.

--- src/memory.c.orig	2020-06-19 21:12:44.000000000 +0200
+++ src/memory.c	2020-07-09 21:13:27.000000000 +0200
@@ -69,7 +69,12 @@ static vm_size_t pagesize;
 /* #endif HAVE_HOST_STATISTICS */
 
 #elif HAVE_SYSCTLBYNAME
+#if HAVE_SYSCTL && defined(KERNEL_NETBSD)
+static int pagesize;
+#include <unistd.h> /* getpagesize() */
+#else
 /* no global variables */
+#endif
 /* #endif HAVE_SYSCTLBYNAME */
 
 #elif KERNEL_LINUX
@@ -97,6 +102,10 @@ static int pagesize;
 #error "No applicable input method."
 #endif
 
+#if KERNEL_NETBSD
+# include <uvm/uvm_extern.h>
+#endif
+
 static bool values_absolute = true;
 static bool values_percentage;
 
@@ -124,7 +133,11 @@ static int memory_init(void) {
   /* #endif HAVE_HOST_STATISTICS */
 
 #elif HAVE_SYSCTLBYNAME
+#if HAVE_SYSCTL && defined(KERNEL_NETBSD)
+  pagesize = getpagesize();
+#else
 /* no init stuff */
+#endif /* HAVE_SYSCTL && defied(KERNEL_NETBSD) */
 /* #endif HAVE_SYSCTLBYNAME */
 
 #elif defined(KERNEL_LINUX)
@@ -225,6 +238,45 @@ static int memory_read_internal(value_li
   /* #endif HAVE_HOST_STATISTICS */
 
 #elif HAVE_SYSCTLBYNAME
+
+#if HAVE_SYSCTL && defined(KERNEL_NETBSD)
+  int mib[] = {CTL_VM, VM_UVMEXP2};
+  struct uvmexp_sysctl uvmexp;
+  gauge_t mem_active;
+  gauge_t mem_inactive;
+  gauge_t mem_free;
+  gauge_t mem_wired;
+  gauge_t mem_kernel;
+  size_t size;
+
+  memset (&uvmexp, 0, sizeof (uvmexp));
+  size = sizeof (uvmexp);
+
+  if (sysctl (mib, 2, &uvmexp, &size, NULL, 0) < 0) {
+    char errbuf[1024];
+    WARNING ("memory plugin: sysctl failed: %s",
+      sstrerror (errno, errbuf, sizeof (errbuf)));
+    return (-1);
+  }
+
+  assert (pagesize > 0);
+  mem_active   = (gauge_t) (uvmexp.active * pagesize);
+  mem_inactive = (gauge_t) (uvmexp.inactive * pagesize);
+  mem_free     = (gauge_t) (uvmexp.free * pagesize);
+  mem_wired    = (gauge_t) (uvmexp.wired * pagesize);
+  mem_kernel   = (gauge_t) ((uvmexp.npages - (
+    uvmexp.active + uvmexp.inactive +
+    uvmexp.free + uvmexp.wired
+    )) * pagesize);
+
+  MEMORY_SUBMIT ("active",   mem_active,
+                 "inactive", mem_inactive,
+                 "free",     mem_free,
+                 "wired",    mem_wired,
+                 "kernel",   mem_kernel);
+/* #endif HAVE_SYSCTL && defined(KERNEL_NETBSD) */
+
+#else /* Other HAVE_SYSCTLBYNAME providers */
   /*
    * vm.stats.vm.v_page_size: 4096
    * vm.stats.vm.v_page_count: 246178
@@ -263,6 +315,8 @@ static int memory_read_internal(value_li
                 (gauge_t)sysctl_vals[3], "active", (gauge_t)sysctl_vals[4],
                 "inactive", (gauge_t)sysctl_vals[5], "cache",
                 (gauge_t)sysctl_vals[6]);
+
+#endif /* HAVE_SYSCTL && KERNEL_NETBSD */
   /* #endif HAVE_SYSCTLBYNAME */
 
 #elif KERNEL_LINUX
