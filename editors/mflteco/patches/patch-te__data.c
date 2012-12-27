$NetBSD: patch-te__data.c,v 1.1 2012/12/27 06:13:20 dholland Exp $

- use const for string constants
- silence warning about initializer

--- te_data.c.orig	1993-08-05 22:29:33.000000000 +0000
+++ te_data.c
@@ -12,7 +12,7 @@
 #include "te_defs.h"
 
 /* error message text */
-char *errors[] =
+const char *errors[] =
 {
 	"> not in iteration",
 	"Can't pop Q register",
@@ -77,8 +77,8 @@ char *errors[] =
 /* the text buffer headers */
 	struct bh buffs[2] =
 {
-		{ NULL, NULL, 0, 0, 0 },
-		{ NULL, NULL, 0, 0, 0 }
+		{ NULL, NULL, 0, 0, 0, 0 },
+		{ NULL, NULL, 0, 0, 0, 0 }
 } ;
 	struct bh *pbuff = buffs;
 
