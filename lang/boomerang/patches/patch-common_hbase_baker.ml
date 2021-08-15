$NetBSD: patch-common_hbase_baker.ml,v 1.1 2021/08/15 06:38:38 dholland Exp $

Fix build with current ocaml.
Silence warning about archaic syntax.

--- common/hbase/baker.ml~	2008-03-03 12:19:20.000000000 +0000
+++ common/hbase/baker.ml
@@ -22,13 +22,13 @@ let go suffix l = 
                   begin
                     let fc = open_in f in
                     let len = in_channel_length fc in 
-                    let buf = String.create len in
+                    let buf = Bytes.create len in
                       really_input fc buf 0 len;
                       close_in fc;                 
                       Hashtbl.replace 
                         srcs 
                         (Filename.chop_extension (Filename.basename f))
-                        (String.escaped buf)
+                        (String.escaped (Bytes.to_string buf))
                   end;
                 loop rest
             | Unix.S_DIR -> 
@@ -36,7 +36,7 @@ let go suffix l = 
                   try 
                     let dc = Unix.readdir dh in
                     let dn = sprintf "%s/%s" f dc in
-                      dirloop dh (if dc = "." or dc =".." then fs else dn::fs)
+                      dirloop dh (if dc = "." || dc = ".." then fs else dn::fs)
                   with End_of_file -> fs in 
                 let dh = Unix.opendir f in
                 let dcs = List.sort compare (dirloop dh []) in
