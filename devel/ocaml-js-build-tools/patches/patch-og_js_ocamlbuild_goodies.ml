$NetBSD: patch-og_js_ocamlbuild_goodies.ml,v 1.1 2016/06/20 14:58:46 jaapb Exp $

NetBSD uses stat -f as well
--- ocamlbuild_goodies/jane_street_ocamlbuild_goodies.ml.orig	2016-05-09 12:01:24.000000000 +0000
+++ ocamlbuild_goodies/jane_street_ocamlbuild_goodies.ml
@@ -65,7 +65,7 @@ let track_external_deps = function
 
     let stat, md5sum =
       match run_and_read "uname" |> String.trim with
-      | "Darwin" ->
+      | "Darwin" | "NetBSD" ->
         (S [A "stat"; A "-f"; A "%d:%i:%m"],
          A "md5")
       | _ ->
