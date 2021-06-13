$NetBSD: patch-src_main_printutils.c,v 1.1 2021/06/13 13:10:47 wen Exp $

--- src/main/printutils.c.orig	2021-04-19 22:02:06.000000000 +0000
+++ src/main/printutils.c
@@ -752,7 +752,7 @@ const char *EncodeString(SEXP s, int w, 
 			for(int j = 0; j < res; j++) *q++ = *p++;
 		    } else {
 # if !defined (__STDC_ISO_10646__) && !defined (Win32)
-			if(!use_ucs) Unicode_warning = TRUE;
+			Unicode_warning = TRUE;
 # endif
 			if(k > 0xffff)
 			    snprintf(buf, 13, "\\U{%06x}", k);
