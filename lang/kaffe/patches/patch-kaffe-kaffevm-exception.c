$NetBSD: patch-kaffe-kaffevm-exception.c,v 1.1 2026/01/03 03:57:09 dholland Exp $

Fix build with gcc14.

--- kaffe/kaffevm/exception.c~	2006-03-15 20:11:12.000000000 +0000
+++ kaffe/kaffevm/exception.c
@@ -421,7 +421,7 @@ dispatchException(Hjava_lang_Throwable* 
 		/*
 		 * if we reach the last jni frame, we're done
 		 */
-		if (lastJniFrame && vmExcept_JNIContains(lastJniFrame, frame->fp)) {
+		if (lastJniFrame && vmExcept_JNIContains(lastJniFrame, (void *)frame->fp)) {
 			thread_data->exceptPtr = lastJniFrame;
 			vmExcept_jumpToHandler(lastJniFrame); /* doesn't return */
 		}
