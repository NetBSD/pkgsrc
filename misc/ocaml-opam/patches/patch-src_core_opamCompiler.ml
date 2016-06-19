$NetBSD: patch-src_core_opamCompiler.ml,v 1.1 2016/06/19 23:23:02 jaapb Exp $

Reflect API change in dose3
--- src/core/opamCompiler.ml.orig	2015-04-27 07:46:51.000000000 +0000
+++ src/core/opamCompiler.ml
@@ -30,7 +30,7 @@ module Version = struct
 
   type constr = (OpamFormula.relop * t) OpamFormula.formula
 
-  let compare v1 v2 = Debian.Version.compare (to_string v1) (to_string v2)
+  let compare v1 v2 = Versioning.Debian.compare (to_string v1) (to_string v2)
 
   let eval_relop relop v1 v2 = OpamFormula.check_relop relop (compare v1 v2)
 
