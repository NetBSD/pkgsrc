$NetBSD: patch-src_libsablevm_lib__init.c,v 1.1 2017/02/14 21:27:40 joerg Exp $

--- src/libsablevm/lib_init.c.orig	2017-01-10 10:03:21.519460366 +0000
+++ src/libsablevm/lib_init.c
@@ -6,7 +6,7 @@
  * modification of this source file.                               *
  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
-static pthread_once_t _svmv_init_once = { PTHREAD_ONCE_INIT };	/* internal_init should only be called once! */
+static pthread_once_t _svmv_init_once = PTHREAD_ONCE_INIT;	/* internal_init should only be called once! */
 static int _svmv_init_result = JNI_ERR;	/* JNI_OK when internal_init succeeds */
 
 /*
