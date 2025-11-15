$NetBSD: patch-stream_url.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- stream/url.c.orig	2025-10-08 03:40:05.333407223 +0000
+++ stream/url.c
@@ -332,8 +332,8 @@ url_unescape_string(char *outbuf, const 
         for (i=0;i<len;i++){
 		c = inbuf[i];
 		if (c == '%' && i<len-2) { //must have 2 more chars
-			c1 = toupper(inbuf[i+1]); // we need uppercase characters
-			c2 = toupper(inbuf[i+2]);
+			c1 = toupper((unsigned char)(inbuf[i+1])); // we need uppercase characters
+			c2 = toupper((unsigned char)(inbuf[i+2]));
 			if (	((c1>='0' && c1<='9') || (c1>='A' && c1<='F')) &&
 				((c2>='0' && c2<='9') || (c2>='A' && c2<='F')) ) {
 				if (c1>='0' && c1<='9') c1-='0';
@@ -357,7 +357,7 @@ url_escape_string_part(char *outbuf, con
 	for  (i=0;i<len;i++) {
 		c = inbuf[i];
                 if ((c=='%') && i<len-2 ) { //need 2 more characters
-                    c1=toupper(inbuf[i+1]); c2=toupper(inbuf[i+2]); // need uppercase chars
+                    c1=toupper((unsigned char)(inbuf[i+1])); c2=toupper((unsigned char)(inbuf[i+2])); // need uppercase chars
                    } else {
                     c1=129; c2=129; //not escape chars
                    }
