$NetBSD: patch-src_main.c,v 1.1 2017/07/24 10:07:44 maya Exp $

Pull in upstream commit:
[PATCH] scanner: Use prefix when defining yywrap to avoid redefinition.
Fixes regression introduced in v2.6.3.

--- src/main.c.orig	2016-12-29 20:03:14.000000000 +0000
+++ src/main.c
@@ -1586,9 +1586,9 @@ void readin (void)
 	if (!do_yywrap) {
 		if (!C_plus_plus) {
 			 if (reentrant)
-				outn ("\n#define yywrap(yyscanner) (/*CONSTCOND*/1)");
+				out_str ("\n#define %swrap(yyscanner) (/*CONSTCOND*/1)\n", prefix);
 			 else
-				outn ("\n#define yywrap() (/*CONSTCOND*/1)");
+				out_str ("\n#define %swrap() (/*CONSTCOND*/1)\n", prefix);
 		}
 		outn ("#define YY_SKIP_YYWRAP");
 	}
-- 
2.13.1

