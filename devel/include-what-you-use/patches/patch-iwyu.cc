$NetBSD: patch-iwyu.cc,v 1.1 2017/03/17 22:39:31 adam Exp $

Fix for LLVM 4.0.0.

--- iwyu.cc.orig	2017-03-17 20:45:17.000000000 +0000
+++ iwyu.cc
@@ -3552,7 +3552,7 @@ class IwyuAstConsumer
 
       // Force parsing and AST building of the yet-uninstantiated function
       // template body.
-      clang::LateParsedTemplate* lpt = sema.LateParsedTemplateMap[fd];
+      clang::LateParsedTemplate* lpt = sema.LateParsedTemplateMap[fd].get();
       sema.LateTemplateParser(sema.OpaqueParser, *lpt);
     }
   }
