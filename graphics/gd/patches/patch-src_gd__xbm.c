$NetBSD: patch-src_gd__xbm.c,v 1.1 2018/02/25 14:34:22 rillig Exp $

Fix undefined behavior while using <ctype.h> functions.

See https://github.com/libgd/libgd/pull/433

--- src/gd_xbm.c.orig	2017-08-30 11:05:54.000000000 +0000
+++ src/gd_xbm.c
@@ -239,7 +239,8 @@ BGD_DECLARE(void) gdImageXbmCtx(gdImageP
 	} else {
 		for (i=0; i<l; i++) {
 			/* only in C-locale isalnum() would work */
-			if (!isupper(name[i]) && !islower(name[i]) && !isdigit(name[i])) {
+			unsigned char ch = name[i];
+			if (!isupper(ch) && !islower(ch) && !isdigit(ch)) {
 				name[i] = '_';
 			}
 		}
