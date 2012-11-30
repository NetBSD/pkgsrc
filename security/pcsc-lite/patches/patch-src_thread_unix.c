$NetBSD: patch-src_thread_unix.c,v 1.2 2012/11/30 14:28:55 gdt Exp $

Make sure libpscslite.so is not linked against -lpthread on NetBSD, as
loading libpthread.so through dlopen() is now forbidden.

--- ./src/thread_unix.c.orig	2012-10-24 06:22:45.000000000 +0200
+++ ./src/thread_unix.c	2012-10-24 06:23:57.000000000 +0200
@@ -58,9 +58,9 @@
 		return pthread_mutex_unlock(mMutex);
 	else
 		return -1;
 }
-
+#ifndef LIBPCSCLITE
 INTERNAL int SYS_ThreadCreate(PCSCLITE_THREAD_T * pthThread, int attributes,
 	PCSCLITE_THREAD_FUNCTION(pvFunction), LPVOID pvArg)
 {
 	pthread_attr_t attr;
@@ -120,5 +120,5 @@
 INTERNAL int SYS_ThreadSetCancelType(int type, int *oldtype)
 {
 	return pthread_setcanceltype(type, oldtype);
 }
-
+#endif /* LIBPCSCLITE */ 
