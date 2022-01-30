$NetBSD: patch-quickjs-libc.c,v 1.3 2022/01/30 10:55:03 he Exp $

Portability patch for NetBSD.

--- quickjs-libc.c.orig	2021-03-27 10:00:32.000000000 +0000
+++ quickjs-libc.c
@@ -675,6 +675,8 @@ static JSValue js_std_unsetenv(JSContext
     return JS_UNDEFINED;
 }
 
+extern char **environ; /* Needed at least for NetBSD-8.0-x86_64. */
+
 /* return an object containing the list of the available environment
    variables. */
 static JSValue js_std_getenviron(JSContext *ctx, JSValueConst this_val,
@@ -1912,7 +1914,7 @@ static void os_signal_handler(int sig_nu
     os_pending_signals |= ((uint64_t)1 << sig_num);
 }
 
-#if defined(_WIN32)
+#if defined(_WIN32) || defined(__NetBSD__)
 typedef void (*sighandler_t)(int sig_num);
 #endif
 
