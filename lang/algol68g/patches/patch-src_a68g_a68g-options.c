$NetBSD: patch-src_a68g_a68g-options.c,v 1.3 2025/12/25 15:06:12 rhialto Exp $

* Enable compiler for *BSD.

--- src/a68g/a68g-options.c.orig	2025-12-02 17:58:48.000000000 +0000
+++ src/a68g/a68g-options.c
@@ -547,11 +547,11 @@ BOOL_T need_library (OPTION_LIST_T *i)
     #endif
   }
   if (eq (q, "linux")) {
-    #if defined (BUILD_LINUX)
+    #if defined (BUILD_LINUX) || defined(BUILD_BSD)
       return (A68G_TRUE);
     #else
       io_close_tty_line ();
-      WRITE (A68G_STDERR, "linux required - exiting graciously");
+      WRITE (A68G_STDERR, "BSD or linux required - exiting graciously");
       a68g_exit (EXIT_SUCCESS);
     #endif
   }
