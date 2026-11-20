$NetBSD: patch-src_mainfunction.c,v 1.1 2026/11/20 15:57:11 ktnb Exp $

ctype fix for NetBSD 11

--- src/mainfunction.c.orig	2026-11-20 14:20:46.610621143 +0000
+++ src/mainfunction.c
@@ -233,7 +233,7 @@ work(char ***message, char **type, unsigned long *line
 					int digit_val = 1;
 					for (unsigned i = 0; token[i] != 0; i++)
 					{
-						if (!isdigit(token[i]))
+						if (!isdigit((unsigned char)token[i]))
 							digit_val = 0;
 					}
 					if (digit_val)	/* go to specified line */
