$NetBSD: patch-kernel_univ.ml,v 1.1 2014/10/09 22:19:01 jaapb Exp $

Fix comment.
--- kernel/univ.ml.orig	2014-04-24 15:13:03.000000000 +0000
+++ kernel/univ.ml
@@ -226,7 +226,7 @@ let reprleq g arcu =
 
 
 (* between : UniverseLevel.t -> canonical_arc -> canonical_arc list *)
-(* between u v = {w|u<=w<=v, w canonical}          *)
+(* between u v = { w | u<=w<=v, w canonical}          *)
 (* between is the most costly operation *)
 
 let between g arcu arcv =
