$NetBSD: patch-src_cairotalk.c,v 1.1 2020/08/11 18:45:25 joerg Exp $

Deal with R-4.0.2 API change.

--- src/cairotalk.c.orig	2020-08-10 12:15:24.950964228 +0000
+++ src/cairotalk.c
@@ -514,7 +514,7 @@ static void CairoGD_MetricInfo(int c,  R
 	} else if (gc->fontface == 5) {
 		char s[2];
 		s[0] = c; s[1] = '\0';
-		AdobeSymbol2utf8(str, s, 16);		
+		AdobeSymbol2utf8(str, s, 16, TRUE);
 	} else if(Unicode) {
 		Rf_ucstoutf8(str, (unsigned int) c);
 	} else {
