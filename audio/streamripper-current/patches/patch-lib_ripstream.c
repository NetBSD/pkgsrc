$NetBSD: patch-lib_ripstream.c,v 1.1 2012/02/15 22:55:16 hans Exp $

--- lib/ripstream.c.orig	2008-12-27 15:32:07.000000000 +0100
+++ lib/ripstream.c	2012-01-11 21:38:08.772278869 +0100
@@ -731,7 +731,7 @@ write_id3v2_frame(RIP_MANAGER_INFO* rmi,
     char bigbuf[HEADER_SIZE] = "";
     ID3V2frame id3v2frame;
 #ifndef WIN32
-    __uint32_t framesize = 0;
+    uint32_t framesize = 0;
 #else
     unsigned long int framesize = 0;
 #endif
