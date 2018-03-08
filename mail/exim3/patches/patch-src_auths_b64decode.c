$NetBSD: patch-src_auths_b64decode.c,v 1.1 2018/03/08 15:14:54 maya Exp $

CVE-2018-6789 off by one
From https://github.com/Exim/exim/commit/062990cc1b2f9e5d82a413b53c8f0569075de700

--- src/auths/b64decode.c.orig	2002-04-04 12:56:16.000000000 +0000
+++ src/auths/b64decode.c
@@ -43,9 +43,12 @@ int
 auth_b64decode(char *code, char **ptr)
 {
 register int x, y;
-char *result = store_get(3*((int)strlen(code)/4) + 1);
+char *result;
 
-*ptr = result;
+{
+  int l = strlen(code);
+  *ptr = result = store_get(1 + l/4 * 3 + l%4);
+}
 
 /* Each cycle of the loop handles a quantum of 4 input bytes. For the last
 quantum this may decode to 1, 2, or 3 output bytes. */
