$NetBSD: patch-source_screen.c,v 1.1 2015/07/27 22:31:30 wiz Exp $

Fixes incompatible pointer type error.

--- source/screen.c.orig	2011-04-29 08:21:18.000000000 +0000
+++ source/screen.c
@@ -613,7 +613,7 @@ display_text(ustr, length)
 				else
 				{
 					retval = iconv(converter,
-					               &str, &length,
+					               (const char**)&str, &length,
 					               &outptr, &outsize);
 				}
 			
