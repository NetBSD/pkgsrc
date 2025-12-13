$NetBSD: patch-mod__http.c,v 1.1 2025/12/13 16:42:03 vins Exp $

--- mod_http.c.orig	2003-11-19 14:38:02.000000000 +0000
+++ mod_http.c
@@ -919,7 +919,7 @@ static char * formatGetString(char * s) 
     if (s[i] == '%') {
       ascii[0] = s[i+1];
       ascii[1] = s[i+2];
-      buf[j++] = atoi(ascii);
+      buf[j++] = strtol(ascii, NULL, 16);
       i = i+3;
     } else {
       buf[j++] = s[i];
