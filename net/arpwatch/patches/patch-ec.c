$NetBSD: patch-ec.c,v 1.1 2026/10/25 15:27:12 taca Exp $

* Pass correct type to ctype(3) function.

--- ec.c.orig	2026-10-25 13:23:21.630688409 +0000
+++ ec.c
@@ -168,7 +168,7 @@ ec_loop(register FILE *f, ec_process fn,
 				sawblank = 0;
 			}
 			*cp2++ = *cp++;
-			while (isspace((int)*cp)) {
+			while (isspace((unsigned char)*cp)) {
 				++cp;
 				sawblank = 1;
 			}
