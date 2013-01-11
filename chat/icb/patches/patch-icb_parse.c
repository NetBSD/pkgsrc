$NetBSD: patch-icb_parse.c,v 1.1 2013/01/11 13:24:32 joerg Exp $

--- icb/parse.c.orig	2013-01-11 12:54:12.000000000 +0000
+++ icb/parse.c
@@ -12,8 +12,7 @@ char *nextword();
 char *argv[10];
 static char sbuf[1024];
 
-parse(s)
-char *s;
+void parse(char *s)
 {
 	char cmdbuf[1024], *p;
 	int result;
