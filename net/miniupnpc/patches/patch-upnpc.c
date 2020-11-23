$NetBSD: patch-upnpc.c,v 1.1 2020/11/23 20:15:19 nia Exp $

ctype arguments must be unsigned char.

--- upnpc.c.orig	2020-11-09 19:43:35.000000000 +0000
+++ upnpc.c
@@ -53,7 +53,7 @@ int is_int(char const* s)
 		return 0;
 	while(*s) {
 		/* #define isdigit(c) ((c) >= '0' && (c) <= '9') */
-		if(!isdigit(*s))
+		if(!isdigit((unsigned char)*s))
 			return 0;
 		s++;
 	}
