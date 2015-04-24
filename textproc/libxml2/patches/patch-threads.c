$NetBSD: patch-threads.c,v 1.5 2015/04/24 11:32:29 spz Exp $

* Treat OpenBSD and MirBSD same as Linux to avoid linking with libpthread
* NetBSD<4.99.36 and FreeBSD<7.0 lack pthread_equal() stub function in libc
* pthread_once_t cast needed to avoid compilation error

--- threads.c.orig	2014-10-13 07:02:28.000000000 +0000
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
