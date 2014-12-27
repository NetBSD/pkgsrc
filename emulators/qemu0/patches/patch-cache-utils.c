$NetBSD: patch-cache-utils.c,v 1.1 2014/12/27 01:53:55 dholland Exp $

Add NetBSD support for PowerPC cache line handling. From Ben Gergely
in PR 48865.

--- cache-utils.c~	2011-10-12 16:41:43.000000000 +0000
+++ cache-utils.c
@@ -57,7 +57,7 @@ static void ppc_init_cacheline_sizes(voi
 }
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -69,8 +69,13 @@ static void ppc_init_cacheline_sizes(voi
 {
     size_t len = 4;
     unsigned cacheline;
+#ifdef __NetBSD__
+    static const char sysctlname[] = "machdep.cachelinesize";
+#else
+    static const char sysctlname[] = "machdep.cacheline_size";
+#endif
 
-    if (sysctlbyname ("machdep.cacheline_size", &cacheline, &len, NULL, 0)) {
+    if (sysctlbyname (sysctlname, &cacheline, &len, NULL, 0)) {
         fprintf(stderr, "sysctlbyname machdep.cacheline_size failed: %s\n",
                 strerror(errno));
         exit(1);
