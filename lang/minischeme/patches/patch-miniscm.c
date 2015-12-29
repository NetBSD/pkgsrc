$NetBSD: patch-miniscm.c,v 1.2 2015/12/29 23:34:51 dholland Exp $

Avoid implicit int.
Use C89.

--- miniscm.c.orig	2013-01-11 15:16:49.000000000 +0000
+++ miniscm.c
@@ -567,8 +567,7 @@ char   *name;
  *  We use algorithm E (Kunuth, The Art of Computer Programming Vol.1,
  *  sec.3.5) for marking.
  */
-mark(a)
-pointer a;
+static void mark(pointer a)
 {
 	register pointer t, q, p;
 
