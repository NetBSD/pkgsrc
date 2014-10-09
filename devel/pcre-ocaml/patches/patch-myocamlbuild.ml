$NetBSD: patch-myocamlbuild.ml,v 1.1 2014/10/09 19:39:24 jaapb Exp $

Deal with reorder issues by linking pcre_stubs statically
--- myocamlbuild.ml.orig	2014-07-06 14:49:44.000000000 +0000
+++ myocamlbuild.ml
@@ -539,7 +539,7 @@ module MyOCamlbuildBase = struct
                         A("-l"^(nm_libstubs lib))]);
 
                    flag ["link"; "library"; "ocaml"; "native"; tag_libstubs lib]
-                     (S[A"-cclib"; A("-l"^(nm_libstubs lib))]);
+                     (S[A"-cclib"; A("lib/lib"^(nm_libstubs lib)^".a")]);
 
                    flag ["link"; "program"; "ocaml"; "byte"; tag_libstubs lib]
                      (S[A"-dllib"; A("dll"^(nm_libstubs lib))]);
