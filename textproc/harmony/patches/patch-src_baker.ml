$NetBSD: patch-src_baker.ml,v 1.1 2018/03/14 06:27:21 dholland Exp $

Fix build with ocaml 4.06.

--- src/baker.ml~	2006-01-23 16:01:51.000000000 +0000
+++ src/baker.ml
@@ -21,13 +21,13 @@ let rec loop = function
               begin
                 let fc = open_in f in
                 let len = in_channel_length fc in 
-                let buf = String.create len in
+                let buf = Bytes.create len in
                   really_input fc buf 0 len;
                   close_in fc;                 
                   Hashtbl.replace 
                     srcs 
                     (Filename.chop_extension (Filename.basename f))
-                    (String.escaped buf)
+                    (String.escaped (Bytes.to_string buf))
               end;
             loop rest
         | Unix.S_DIR -> 
