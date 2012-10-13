$NetBSD: patch-props.ml,v 1.1 2012/10/13 09:05:12 wiz Exp $

r511 | vouillon | 2012-09-17 16:09:03 +0200 (Mon, 17 Sep 2012) | 3 lines

* Use hash function from OCaml 3.x for comparing archives, even when
  compiled with OCaml 4.x

--- props.ml.orig	2010-04-15 17:29:31.000000000 +0000
+++ props.ml
@@ -305,7 +305,7 @@ let hash id h =
     (match id with
        IdIgnored   -> -1
      | IdNumeric i -> i
-     | IdNamed nm  -> Hashtbl.hash nm)
+     | IdNamed nm  -> Uutil.hash nm)
     h
 
 let similar id id' =
@@ -609,7 +609,7 @@ type t = string option
 
 let dummy = None
 
-let hash t h = Uutil.hash2 (Hashtbl.hash t) h
+let hash t h = Uutil.hash2 (Uutil.hash t) h
 
 let similar t t' =
   not (Prefs.read Osx.rsrc) || t = t'
