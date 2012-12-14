$NetBSD: patch-src_utils.c,v 1.1 2012/12/14 23:50:36 pettai Exp $

Make sure libpscslite.so is not linked against -lpthread on NetBSD, as
loading libpthread.so through dlopen() is now forbidden.

--- src/utils.c.orig	2012-12-12 09:49:16.000000000 +0000
+++ src/utils.c
@@ -117,6 +117,7 @@ long int time_sub(struct timeval *a, str
 	return r.tv_sec * 1000000 + r.tv_usec;
 } /* time_sub */
 
+#ifndef LIBPCSCLITE
 int ThreadCreate(pthread_t * pthThread, int attributes,
 	PCSCLITE_THREAD_FUNCTION(pvFunction), LPVOID pvArg)
 {
@@ -142,3 +143,4 @@ int ThreadCreate(pthread_t * pthThread, 
 	ret = pthread_attr_destroy(&attr);
 	return ret;
 }
+#endif /* LIBPCSCLITE */
