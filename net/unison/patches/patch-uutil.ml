$NetBSD: patch-uutil.ml,v 1.1 2012/10/13 09:05:12 wiz Exp $

r511 | vouillon | 2012-09-17 16:09:03 +0200 (Mon, 17 Sep 2012) | 3 lines

* Use hash function from OCaml 3.x for comparing archives, even when
  compiled with OCaml 4.x

--- uutil.ml.orig	2010-04-15 17:29:31.000000000 +0000
+++ uutil.ml
@@ -34,6 +34,10 @@ let myNameAndVersion = myName ^ " " ^ my
 
 let hash2 x y = (17 * x + 257 * y) land 0x3FFFFFFF
 
+external hash_param : int -> int -> 'a -> int = "caml_hash_univ_param" "noalloc"
+
+let hash x = hash_param 10 100 x
+
 (*****************************************************************************)
 (*                             File sizes                                    *)
 (*****************************************************************************)
