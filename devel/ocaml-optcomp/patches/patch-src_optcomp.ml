$NetBSD: patch-src_optcomp.ml,v 1.1 2018/01/22 11:22:40 jaapb Exp $

Compatibility fix with OCaml 4.06 (upstream pull request)
--- src/optcomp.ml.orig	2014-05-13 08:24:26.000000000 +0000
+++ src/optcomp.ml
@@ -84,9 +84,9 @@ let rec print mode current_fname current
                 (* Go to the right position in the input. *)
                 if pos_in ic <> off then seek_in ic off;
                 (* Read the part to copy. *)
-                let str = String.create len in
-                really_input ic str 0 len;
-                (str, Loc.stop_line loc, Loc.stop_off loc - Loc.stop_bol loc)
+                let buf = Bytes.create len in
+                really_input ic buf 0 len;
+                (Bytes.to_string buf, Loc.stop_line loc, Loc.stop_off loc - Loc.stop_bol loc)
         in
         if current_fname = fname && current_line = line && current_col = col then
           (* If we at the right position, just print the string. *)
