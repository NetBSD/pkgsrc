$NetBSD: patch-path.mli,v 1.1 2012/10/13 09:05:12 wiz Exp $

r511 | vouillon | 2012-09-17 16:09:03 +0200 (Mon, 17 Sep 2012) | 3 lines

* Use hash function from OCaml 3.x for comparing archives, even when
  compiled with OCaml 4.x

--- path.mli.orig	2010-04-15 17:29:31.000000000 +0000
+++ path.mli
@@ -31,8 +31,6 @@ val addSuffixToFinalName : local -> stri
 val addPrefixToFinalName : local -> string -> local
 
 val compare : t -> t -> int
-val equal : local -> local -> bool
-val hash : local -> int
 
 val followLink : local -> bool
 val followPred : Pred.t
