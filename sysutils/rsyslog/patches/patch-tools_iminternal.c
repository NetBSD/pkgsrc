$NetBSD: patch-tools_iminternal.c,v 1.1 2018/01/15 11:01:16 fhajny Exp $

NetBSD lacks pthread_mutex_timedlock.

--- tools/iminternal.c.orig	2018-01-08 12:42:31.000000000 +0000
+++ tools/iminternal.c
@@ -88,7 +88,7 @@ rsRetVal iminternalAddMsg(smsg_t *pMsg)
 	 */
 	to.tv_sec = time(NULL) + 1;
 	to.tv_nsec = 0;
-	#if !defined(__APPLE__)
+	#if !defined(__APPLE__) && !defined(__NetBSD__)
 	r = pthread_mutex_timedlock(&mutList, &to);
 	#else
 	r = pthread_mutex_trylock(&mutList); // must check
