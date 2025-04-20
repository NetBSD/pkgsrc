$NetBSD: patch-Modules_faulthandler.c,v 1.1 2025/04/20 22:51:27 js Exp $

Work around what looks like a compiler bug in GCC 15.

--- Modules/faulthandler.c.orig	2025-04-20 22:48:09.940663976 +0000
+++ Modules/faulthandler.c
@@ -82,8 +82,14 @@ static fault_handler_t faulthandler_hand
        handler fails in faulthandler_fatal_error() */
     {SIGSEGV, 0, "Segmentation fault", }
 };
-static const size_t faulthandler_nsignals = \
-    Py_ARRAY_LENGTH(faulthandler_handlers);
+static const size_t faulthandler_nsignals = 3
+#ifdef SIGBUS
+    + 1
+#endif
+#ifdef SIGILL
+    + 1
+#endif
+;
 
 #ifdef FAULTHANDLER_USE_ALT_STACK
 #  define stack _PyRuntime.faulthandler.stack
