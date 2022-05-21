$NetBSD: patch-main_streams_streams.c,v 1.1 2022/05/21 16:00:11 taca Exp $

* Allow copying files with size zero.

--- main/streams/streams.c.orig	2022-05-10 08:07:35.000000000 +0000
+++ main/streams/streams.c
@@ -1575,10 +1575,8 @@ PHPAPI int _php_stream_copy_to_stream_ex
 
 				*len = haveread += didwrite;
 
-				/* we've got at least 1 byte to read
-				 * less than 1 is an error
-				 * AND read bytes match written */
-				if (mapped == 0 || mapped != didwrite) {
+				/* read bytes match written */
+				if (mapped != didwrite) {
 					return FAILURE;
 				}
 				if (mapped < chunk_size) {
