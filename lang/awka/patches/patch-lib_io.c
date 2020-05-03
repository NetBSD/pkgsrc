$NetBSD: patch-lib_io.c,v 1.1 2020/05/03 15:36:20 rillig Exp $

Prevent array-out-of-bounds access.

https://sourceforge.net/p/awka/bugs/45/

--- lib/io.c.orig	2001-07-11 05:17:06.000000000 +0000
+++ lib/io.c
@@ -644,10 +644,11 @@ _awka_io_addstream( char *name, char fla
 void
 _awka_io_cleanbinchars(a_VAR *var)
 {
-  register char *r, *q;
+  register char *r;
+  unsigned char *q;
 
   r = var->ptr + var->slen;
-  q = var->ptr;
+  q = (unsigned char *) var->ptr;
   if (var->slen >= 8)
   while (q<=(r-8)) 
   {
