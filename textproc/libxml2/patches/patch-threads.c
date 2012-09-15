$NetBSD: patch-threads.c,v 1.3 2012/09/15 10:23:39 adam Exp $

* Treat OpenBSD and MirBSD same as Linux to avoid linking with libpthread
* NetBSD<4.99.36 and FreeBSD<7.0 lack pthread_equal() stub function in libc
* pthread_once_t cast needed to avoid compilation error

--- threads.c.orig	2010-10-15 17:28:30.000000000 +0000
+++ threads.c
@@ -42,13 +42,17 @@
 #include <note.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
 /* #define DEBUG_THREADS */
 
 #ifdef HAVE_PTHREAD_H
 
 static int libxml_is_threaded = -1;
 #ifdef __GNUC__
-#ifdef linux
+#if defined(linux) || defined(__OpenBSD__) || defined(__MirBSD__)
 #if (__GNUC__ == 3 && __GNUC_MINOR__ >= 3) || (__GNUC__ > 3)
 extern int pthread_once (pthread_once_t *__once_control,
                          void (*__init_routine) (void))
@@ -90,6 +94,10 @@ extern int pthread_cond_signal ()
 #endif
 #endif /* linux */
 #endif /* __GNUC__ */
+#if (defined(__NetBSD__) && __NetBSD_Version__ < 499003600) || (defined(__FreeBSD__) && __FreeBSD_version < 700000)
+extern int pthread_equal ()
+	   __attribute((weak));
+#endif /* NetBSD-4, FreeBSD-6 */
 #endif /* HAVE_PTHREAD_H */
 
 /*
@@ -915,7 +923,7 @@ xmlCleanupThreads(void)
 #ifdef HAVE_PTHREAD_H
     if ((libxml_is_threaded)  && (pthread_key_delete != NULL))
         pthread_key_delete(globalkey);
-    once_control = PTHREAD_ONCE_INIT;
+    once_control = (pthread_once_t)PTHREAD_ONCE_INIT;
 #elif defined(HAVE_WIN32_THREADS) && !defined(HAVE_COMPILER_TLS) && (!defined(LIBXML_STATIC) || defined(LIBXML_STATIC_FOR_DLL))
     if (globalkey != TLS_OUT_OF_INDEXES) {
         xmlGlobalStateCleanupHelperParams *p;
