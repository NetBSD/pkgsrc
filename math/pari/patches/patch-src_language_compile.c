$NetBSD: patch-src_language_compile.c,v 1.1 2016/03/03 13:28:22 wiz Exp $

--- src/language/compile.c.orig	2015-03-18 10:33:24.000000000 +0000
+++ src/language/compile.c
@@ -1915,7 +1915,7 @@ compilenode(long n, int mode, long flag)
         op_push(OCpushreal, data_push(strntoGENstr(tree[n].str,tree[n].len)),n);
         break;
       case CSTint:
-        op_push(OCpushgen,  data_push(strtoi((char*)tree[n].str)),n);
+        op_push(OCpushgen,  data_push(pari_strtoi((char*)tree[n].str)),n);
         compilecast(n,Ggen, mode);
         break;
       case CSTstr:
