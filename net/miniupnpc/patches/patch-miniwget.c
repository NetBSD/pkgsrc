$NetBSD: patch-miniwget.c,v 1.1 2020/11/23 20:15:19 nia Exp $

ctype arguments must be unsigned char.

--- miniwget.c.orig	2020-11-09 19:43:34.000000000 +0000
+++ miniwget.c
@@ -249,7 +249,7 @@ getHTTPResponse(SOCKET s, int * size, in
 						if(buf[i] == '\r') i++;
 						if(i<n && buf[i] == '\n') i++;
 					}
-					while(i<n && isxdigit(buf[i])
+					while(i<n && isxdigit((unsigned char)buf[i])
 					     && chunksize_buf_index < (sizeof(chunksize_buf)-1))
 					{
 						chunksize_buf[chunksize_buf_index++] = buf[i];
