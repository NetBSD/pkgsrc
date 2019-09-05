$NetBSD: patch-lib_util_tfork.c,v 1.1 2019/09/05 12:39:56 hauke Exp $

On SunOS (OpenSolaris), pthread_mutex_init() expects a zeroed-out
mutex data structure
    
--- lib/util/tfork.c.orig	2019-01-15 10:07:00.000000000 +0000
+++ lib/util/tfork.c
@@ -281,6 +281,7 @@ static void tfork_global_initialize(void
 	ret = pthread_key_create(&tfork_global_key, tfork_global_destructor);
 	assert(ret == 0);
 
+	memset(&signal_state.mutex, 0, sizeof(pthread_mutex_t));
 	ret = pthread_mutex_init(&signal_state.mutex, NULL);
 	assert(ret == 0);
 
