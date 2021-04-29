$NetBSD: patch-source3_libsmb_pylibsmb.c,v 1.2 2021/04/29 15:21:16 taca Exp $

On SunOS (OpenSolaris), pthread_mutex_init() expects a zeroed-out
mutex data structure

--- source3/libsmb/pylibsmb.c.orig	2019-05-07 08:38:21.000000000 +0000
+++ source3/libsmb/pylibsmb.c
@@ -285,6 +285,7 @@ static int py_tevent_cond_wait(struct py
 {
 	int ret, result;
 
+	memset(&cond->mutex, 0, sizeof(pthread_mutex_t));
 	result = pthread_mutex_init(&cond->mutex, NULL);
 	if (result != 0) {
 		goto fail;
