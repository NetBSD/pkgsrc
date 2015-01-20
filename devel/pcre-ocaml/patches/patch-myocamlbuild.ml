$NetBSD: patch-myocamlbuild.ml,v 1.2 2015/01/20 14:31:09 jaapb Exp $

Use pkgsrc-runtime flag for proper building
--- myocamlbuild.ml.orig	2014-12-12 02:37:43.000000000 +0000
+++ myocamlbuild.ml
@@ -420,6 +420,7 @@ module MyOCamlbuildFindlib = struct
           flag ["ocaml"; "package(threads)"; "doc"] (S[A "-I"; A "+threads"]);
           flag ["ocaml"; "package(threads)"; "link"] (S[A "-thread"]);
           flag ["ocaml"; "package(threads)"; "infer_interface"] (S[A "-thread"]);
+					flag ["ocaml"; "link"; "native"] (S[A "-passopt"; A "-pkgsrc-runtime"]);
 
       | _ ->
           ()
