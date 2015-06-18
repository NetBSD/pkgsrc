$NetBSD: patch-libgc_misc.c,v 1.1 2015/06/18 19:00:26 joerg Exp $

--- libgc/misc.c.orig	2011-11-15 17:22:41.000000000 +0000
+++ libgc/misc.c
@@ -14,10 +14,10 @@
  */
 /* Boehm, July 31, 1995 5:02 pm PDT */
 
-
 #include <stdio.h>
 #include <limits.h>
 #ifndef _WIN32_WCE
+#include <sys/resource.h>
 #include <signal.h>
 #endif
 
@@ -755,6 +755,19 @@ void GC_init_inner()
 	  initial_heap_sz = divHBLKSZ(initial_heap_sz);
 	}
     }
+#ifdef RLIMIT_AS
+    {
+        /*
+         * If there is a VA limit for the process,
+         * keep the heap under 75% if that limit.
+         */
+	struct rlimit lim;
+	if (!getrlimit(RLIMIT_AS, &lim)) {
+	  if (lim.rlim_cur != RLIM_INFINITY && lim.rlim_cur == (word)lim.rlim_cur)
+	    GC_set_max_heap_size(lim.rlim_cur / 2 + lim.rlim_cur / 4);
+	}
+    }
+#endif
     {
 	char * sz_str = GETENV("GC_MAXIMUM_HEAP_SIZE");
 	if (sz_str != NULL) {
