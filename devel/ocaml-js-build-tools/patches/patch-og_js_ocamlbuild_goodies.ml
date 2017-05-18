$NetBSD: patch-og_js_ocamlbuild_goodies.ml,v 1.2 2017/05/18 12:36:25 jperkin Exp $

NetBSD uses stat -f as well
Support SunOS digest(1)

--- ocamlbuild_goodies/jane_street_ocamlbuild_goodies.ml.orig	2016-05-09 12:01:24.000000000 +0000
+++ ocamlbuild_goodies/jane_street_ocamlbuild_goodies.ml
@@ -65,9 +65,12 @@ let track_external_deps = function
 
     let stat, md5sum =
       match run_and_read "uname" |> String.trim with
-      | "Darwin" ->
+      | "Darwin" | "NetBSD" ->
         (S [A "stat"; A "-f"; A "%d:%i:%m"],
          A "md5")
+      | "SunOS" ->
+        (S [A "stat"; A "-c"; A "%d:%i:%Y"],
+         S [A "/bin/digest"; A "-a"; A "md5"])
       | _ ->
         (S [A "stat"; A "-c"; A "%d:%i:%Y"],
          A "md5sum")
