$NetBSD: patch-awka_da.c,v 1.1 2020/05/03 15:36:20 rillig Exp $

Fix array-out-of-bounds access for non-ASCII characters.

https://sourceforge.net/p/awka/bugs/45/

--- awka/da.c.orig	2001-07-06 07:06:19.000000000 +0000
+++ awka/da.c
@@ -140,7 +140,8 @@
 char *
 fixbackslashes(char *str, int which)
 {
-  char *p = str, *q = str, *r;
+  char *p = str, *r;
+  unsigned char *q = (unsigned char *) str;
   size_t len;
 
   /*
