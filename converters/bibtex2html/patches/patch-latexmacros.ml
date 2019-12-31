$NetBSD: patch-latexmacros.ml,v 1.1 2019/12/31 19:46:12 markd Exp $

fixed compilation with recent versions of OCaml 
git commit 8f25afb95a839c9f9522a34013d5c905af14378b 

--- latexmacros.ml.orig	2014-07-04 07:51:21.000000000 +0000
+++ latexmacros.ml
@@ -113,7 +113,7 @@ def "\\textsi" [Print "<i>" ; Print_arg
 (* Basic color support. *)
 
 def "\\textcolor" [ Parameterized (function name ->
-  match String.lowercase name with
+  match String.lowercase_ascii name with
   (* At the moment, we support only the 16 named colors defined in HTML 4.01. *)
   | "black" | "silver" | "gray" | "white" | "maroon" | "red" | "purple" | "fuchsia"
   | "green" | "lime" | "olive" | "yellow" | "navy" | "blue" | "teal" | "aqua" ->
