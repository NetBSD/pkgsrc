$NetBSD: patch-lib_tevent_tevent.c,v 1.1 2019/09/05 12:39:56 hauke Exp $

On SunOS (OpenSolaris), pthread_mutex_init() expects a zeroed-out
mutex data structure
    
--- lib/tevent/tevent.c.orig	2019-01-15 10:07:00.000000000 +0000
+++ lib/tevent/tevent.c
@@ -423,6 +423,7 @@ static int tevent_common_context_constru
 		return ret;
 	}
 
+	memset(&ev->scheduled_mutex, 0, sizeof(pthread_mutex_t));
 	ret = pthread_mutex_init(&ev->scheduled_mutex, NULL);
 	if (ret != 0) {
 		return ret;
