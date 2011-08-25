$NetBSD: patch-mysys_my_init.c,v 1.1 2011/08/25 04:37:18 adam Exp $

Fix for Max OS X 10.7 where pthread_init() exists, but isn't a public interface.

--- mysys/my_init.c.orig	2011-08-25 04:24:59.000000000 +0000
+++ mysys/my_init.c
@@ -99,7 +99,7 @@ my_bool my_init(void)
   fastmutex_global_init();              /* Must be called early */
 #endif
 
-#if defined(HAVE_PTHREAD_INIT)
+#if defined(HAVE_PTHREAD_INIT) && !defined(__APPLE__)
   pthread_init();			/* Must be called before DBUG_ENTER */
 #endif
 
