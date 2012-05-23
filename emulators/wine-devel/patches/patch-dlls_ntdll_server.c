$NetBSD: patch-dlls_ntdll_server.c,v 1.1 2012/05/23 17:48:54 marino Exp $

--- dlls/ntdll/server.c.orig	2011-08-05 17:24:22.000000000 +0000
+++ dlls/ntdll/server.c
@@ -946,7 +946,7 @@ static int get_unix_tid(void)
     int ret = -1;
 #ifdef linux
     ret = syscall( SYS_gettid );
-#elif defined(__sun)
+#elif defined(__sun) || defined(__DragonFly__)
     ret = pthread_self();
 #elif defined(__APPLE__)
     ret = mach_thread_self();
