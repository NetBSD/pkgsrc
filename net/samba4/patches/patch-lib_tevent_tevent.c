$NetBSD: patch-lib_tevent_tevent.c,v 1.4 2022/10/25 07:46:11 wiz Exp $

On SunOS (OpenSolaris), pthread_mutex_init() expects a zeroed-out
mutex data structure

--- lib/tevent/tevent.c.orig	2022-08-08 14:15:39.148190500 +0000
+++ lib/tevent/tevent.c
@@ -476,6 +476,7 @@ static int tevent_common_context_constru
 
 #ifdef HAVE_PTHREAD
 
+	memset(&ev->scheduled_mutex, 0, sizeof(pthread_mutex_t));
 	ret = pthread_mutex_init(&ev->scheduled_mutex, NULL);
 	if (ret != 0) {
 		return ret;
