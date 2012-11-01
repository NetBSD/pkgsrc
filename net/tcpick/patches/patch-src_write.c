$NetBSD: patch-src_write.c,v 1.1 2012/11/01 19:35:20 joerg Exp $

--- src/write.c.orig	2012-10-30 21:54:28.000000000 +0000
+++ src/write.c
@@ -28,7 +28,7 @@
 #include "tcpick.h"
 #include "extern.h"
 
-__inline__ char * 
+char * 
 avail_filename(struct CONN * conn_ptr, 
 	       enum PART side, char * ext)
 /*
@@ -181,7 +181,7 @@ open_file( struct CONN * conn_ptr, 
 	return;
 }
 
-__inline__ int
+int
 flowflush ( struct CONN * conn_ptr, 
 	    struct HOST_DESC * desc, 
 	    u_char * buf,
