$NetBSD: patch-src_genstr.c,v 1.2 2015/12/29 23:34:44 dholland Exp $

Avoid implicit int.
Use C89.

--- src/genstr.c.orig	2012-10-26 13:02:23.000000000 +0000
+++ src/genstr.c
@@ -258,8 +258,7 @@ static blockmainstructure (rb, output_re
 /******************************************************************************
                                                         BLOCKSTRUCTURE       */
 
-static blockstructure (rb)
-     struct BLOCK *rb;
+static void blockstructure (struct BLOCK *rb)
 {
   int i;
   struct DECL *rd;
