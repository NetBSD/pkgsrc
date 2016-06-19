$NetBSD: patch-src_core_opamFilter.ml,v 1.1 2016/06/19 23:23:02 jaapb Exp $

Reflect API change in dose3
--- src/core/opamFilter.ml.orig	2015-04-27 07:46:51.000000000 +0000
+++ src/core/opamFilter.ml
@@ -203,7 +203,7 @@ let rec reduce_aux env = function
      | FUndef, _ | _, FUndef -> FUndef
      | e,f ->
        FBool (OpamFormula.check_relop relop
-                (Debian.Version.compare (value_string e) (value_string f))))
+                (Versioning.Debian.compare (value_string e) (value_string f))))
   | FAnd (e,f) -> logop2 (&&) false (reduce env e) (reduce env f)
   | FOr (e,f) -> logop2 (||) true (reduce env e) (reduce env f)
   | FNot e -> logop1 not (reduce env e)
