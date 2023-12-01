$NetBSD: patch-src_a68g_a68g-options.c,v 1.2 2023/12/01 18:35:12 rhialto Exp $

* Enable compiler for *BSD.

--- src/a68g/a68g-options.c.orig	2023-10-27 20:14:34.000000000 +0000
+++ src/a68g/a68g-options.c
@@ -478,7 +478,7 @@ BOOL_T need_library (OPTION_LIST_T *i)
 #endif
   }
   if (eq (q, "linux")) {
-#if defined (BUILD_LINUX)
+#if defined (BUILD_LINUX) || defined(BUILD_BSD)
     return (A68_TRUE);
 #else
     io_close_tty_line ();
