$NetBSD: patch-cbtcommon_text__util.c,v 1.1 2023/06/26 15:42:53 schmonz Exp $

memfrob() is glibc-specific.

--- cbtcommon/text_util.c.orig	2005-05-26 03:39:40.000000000 +0000
+++ cbtcommon/text_util.c
@@ -236,7 +236,7 @@ void trim_zeros_after_decimal( char* src
     }
 }
 
-#ifdef linux
+#ifdef __GLIBC__
 extern void *memfrob(void *, size_t);
 #else
 static void * memfrob(void * mem, size_t len)
