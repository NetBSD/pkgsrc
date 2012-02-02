$NetBSD: patch-main_streams_cast.c,v 1.1 2012/02/02 15:44:09 taca Exp $

Fix build problem of newer NetBSD.

--- main/streams/cast.c.orig	2012-01-01 13:15:04.000000000 +0000
+++ main/streams/cast.c
@@ -34,7 +34,7 @@
 typedef struct {
 	int (*reader)(void *, char *, int);
 	int (*writer)(void *, const char *, int);
-	fpos_t (*seeker)(void *, fpos_t, int);
+	off_t (*seeker)(void *, off_t, int);
 	int (*closer)(void *);
 } COOKIE_IO_FUNCTIONS_T;
 
@@ -68,11 +68,11 @@ static int stream_cookie_writer(void *co
 	return php_stream_write((php_stream *)cookie, (char *)buffer, size);
 }
 
-static fpos_t stream_cookie_seeker(void *cookie, off_t position, int whence)
+static off_t stream_cookie_seeker(void *cookie, off_t position, int whence)
 {
 	TSRMLS_FETCH();
 
-	return (fpos_t)php_stream_seek((php_stream *)cookie, position, whence);
+	return (off_t)php_stream_seek((php_stream *)cookie, position, whence);
 }
 
 static int stream_cookie_closer(void *cookie)
