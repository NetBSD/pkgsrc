$NetBSD: patch-src_utils.c,v 1.3 2020/06/20 19:03:37 adam Exp $

Make sure libpcsclite.so is not linked against -lpthread on NetBSD, as
loading libpthread.so through dlopen() is now forbidden.

--- src/utils.c.orig	2014-08-08 16:57:27.000000000 +0000
+++ src/utils.c
@@ -151,6 +151,7 @@ long int time_sub(struct timeval *a, str
 	return r.tv_sec * 1000000 + r.tv_usec;
 } /* time_sub */
 
+#ifndef LIBPCSCLITE
 int ThreadCreate(pthread_t * pthThread, int attributes,
 	PCSCLITE_THREAD_FUNCTION(pvFunction), LPVOID pvArg)
 {
@@ -186,3 +187,4 @@ error:
 	pthread_attr_destroy(&attr);
 	return ret;
 }
+#endif /*  LIBPCSCLITE */
