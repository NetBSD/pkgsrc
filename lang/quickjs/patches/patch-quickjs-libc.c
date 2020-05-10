$NetBSD: patch-quickjs-libc.c,v 1.2 2020/05/10 10:17:06 rillig Exp $

Portability patch for NetBSD.

--- quickjs-libc.c.orig	2020-04-12 13:18:13.000000000 +0000
+++ quickjs-libc.c
@@ -1712,7 +1712,7 @@ static void os_signal_handler(int sig_nu
     os_pending_signals |= ((uint64_t)1 << sig_num);
 }
 
-#if defined(_WIN32)
+#if defined(_WIN32) || defined(__NetBSD__)
 typedef void (*sighandler_t)(int sig_num);
 #endif
 
@@ -2442,6 +2442,8 @@ static int my_execvpe(const char *filena
     return -1;
 }
 
+extern char **environ; /* Needed at least for NetBSD-8.0-x86_64. */
+
 /* exec(args[, options]) -> exitcode */
 static JSValue js_os_exec(JSContext *ctx, JSValueConst this_val,
                           int argc, JSValueConst *argv)
