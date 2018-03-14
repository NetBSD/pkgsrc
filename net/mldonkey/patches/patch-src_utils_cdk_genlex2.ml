$NetBSD: patch-src_utils_cdk_genlex2.ml,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/cdk/genlex2.ml~	2003-04-22 22:33:39.000000000 +0000
+++ src/utils/cdk/genlex2.ml
@@ -28,7 +28,7 @@ type token =
 
 (* The string buffering machinery *)
 
-let initial_buffer = String.create 32
+let initial_buffer = Bytes.create 32
 
 let buffer = ref initial_buffer
 let bufpos = ref 0
@@ -36,16 +36,18 @@ let bufpos = ref 0
 let reset_buffer () = buffer := initial_buffer; bufpos := 0
 
 let store c =
-  if !bufpos >= String.length !buffer then
+  if !bufpos >= Bytes.length !buffer then
     begin
-      let newbuffer = String.create (2 * !bufpos) in
-      String.blit !buffer 0 newbuffer 0 !bufpos; buffer := newbuffer
+      let newbuffer = Bytes.create (2 * !bufpos) in
+      Bytes.blit !buffer 0 newbuffer 0 !bufpos; buffer := newbuffer
     end;
-  String.set !buffer !bufpos c;
+  Bytes.set !buffer !bufpos c;
   incr bufpos
 
 let get_string () =
-  let s = String.sub !buffer 0 !bufpos in buffer := initial_buffer; s
+  let s = Bytes.to_string (Bytes.sub !buffer 0 !bufpos) in
+  buffer := initial_buffer;
+  s
 
 (* The lexer *)
 
