$NetBSD: patch-compiler_cpp_src_thrifty.yy,v 1.1 2013/05/14 19:15:36 joerg Exp $

--- compiler/cpp/src/thrifty.yy.orig	2013-05-03 21:59:16.000000000 +0000
+++ compiler/cpp/src/thrifty.yy
@@ -618,7 +618,7 @@ ConstValue:
       $$ = new t_const_value();
       $$->set_integer($1);
       if ($1 < INT32_MIN || $1 > INT32_MAX) {
-        pwarning(1, "64-bit constant \"%"PRIi64"\" may not work in all languages.\n", $1);
+        pwarning(1, "64-bit constant \"%" PRIi64 "\" may not work in all languages.\n", $1);
       }
     }
 | tok_dub_constant
