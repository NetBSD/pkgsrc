$NetBSD: patch-test.ml,v 1.1 2018/03/14 11:16:15 dholland Exp $

Fix build with ocaml 4.06.

--- test.ml~	2010-04-15 17:29:31.000000000 +0000
+++ test.ml
@@ -48,9 +48,9 @@ let rec remove_file_or_dir d =
 
 let read_chan chan =
   let nbytes = in_channel_length chan in
-  let string = String.create nbytes in
+  let string = Bytes.create nbytes in
   really_input chan string 0 nbytes;
-  string
+  Bytes.to_string string
 
 let read file =
 (*
