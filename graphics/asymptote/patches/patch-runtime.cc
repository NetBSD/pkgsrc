$NetBSD: patch-runtime.cc,v 1.1 2012/03/10 21:14:52 markd Exp $

--- runtime.cc.orig	2011-11-16 21:40:24.000000000 +0000
+++ runtime.cc
@@ -274,7 +274,7 @@ void gen_runtime3(stack *Stack)
 {
   real x=vm::pop<real>(Stack);
 #line 241 "runtime.in"
-  {Stack->push<bool>(isnan(x)); return;}
+  {Stack->push<bool>(std::isnan(x)); return;}
 }
 
 #line 245 "runtime.in"
