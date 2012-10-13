$NetBSD: patch-path.ml,v 1.1 2012/10/13 09:05:11 wiz Exp $

r511 | vouillon | 2012-09-17 16:09:03 +0200 (Mon, 17 Sep 2012) | 3 lines

* Use hash function from OCaml 3.x for comparing archives, even when
  compiled with OCaml 4.x

--- path.ml.orig	2010-04-15 17:29:31.000000000 +0000
+++ path.ml
@@ -202,10 +202,6 @@ let addPrefixToFinalName path prefix =
     assert (not (isEmpty path));
     prefix ^ path
 
-(* No need to perform case normalization on local paths *)
-let hash p = Hashtbl.hash p
-let equal (p1 : local) (p2 : local) = p1 = p2
-
 (* Pref controlling whether symlinks are followed. *)
 let followPred = Pred.create ~advanced:true "follow"
     ("Including the preference \\texttt{-follow \\ARG{pathspec}} causes Unison to \
