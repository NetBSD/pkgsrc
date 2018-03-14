$NetBSD: patch-src_toplevel.ml,v 1.1 2018/03/14 06:27:21 dholland Exp $

Fix build with ocaml 4.06.

--- src/toplevel.ml~	2006-05-24 22:47:36.000000000 +0000
+++ src/toplevel.ml
@@ -150,7 +150,7 @@ let cp_or_del f g =
       (* slurp in f, write to g *)
       let inc = open_in_bin f in
       let len = in_channel_length inc in
-      let buf = String.make len '\000' in
+      let buf = Bytes.make len '\000' in
         really_input inc buf 0 len;
         close_in inc;
         let outc = open_out_bin g in
