$NetBSD: patch-src_pl-thread.c,v 1.1 2018/12/10 14:59:50 leot Exp $

Add support for NetBSD pthread_setname_np(3).

--- src/pl-thread.c.orig	2018-01-12 12:04:38.000000000 +0000
+++ src/pl-thread.c
@@ -1635,10 +1635,15 @@ set_os_thread_name_from_charp(const char
   if ( pthread_setname_np(name) == 0 )
     return TRUE;
 #else
+#if defined(__NetBSD__)
+  if ( pthread_setname_np(pthread_self(), "%s", (void *)name) == 0 )
+    return TRUE;
+#else
   if ( pthread_setname_np(pthread_self(), name) == 0 )
     return TRUE;
 #endif
 #endif
+#endif
   return FALSE;
 }
 
