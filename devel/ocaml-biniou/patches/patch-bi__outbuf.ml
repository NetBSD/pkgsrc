$NetBSD: patch-bi__outbuf.ml,v 1.1 2018/03/11 02:30:34 dholland Exp $

Fix up mutable strings to make it build with ocaml 4.06.

--- bi_outbuf.ml~	2017-05-04 17:38:05.000000000 +0000
+++ bi_outbuf.ml
@@ -1,5 +1,5 @@
 type t = {
-  mutable o_s : string;
+  mutable o_s : bytes;
   mutable o_max_len : int;
   mutable o_len : int;
   mutable o_offs : int;
@@ -21,8 +21,8 @@ let really_extend b n =
       else
 	Sys.max_string_length
   in
-  let s = String.create slen in
-  String.blit b.o_s 0 s 0 b.o_len;
+  let s = Bytes.create slen in
+  Bytes.blit b.o_s 0 s 0 b.o_len;
   b.o_s <- s;
   b.o_max_len <- slen
 
@@ -37,7 +37,7 @@ let flush_to_channel oc = flush_to_outpu
 
 
 let create ?(make_room = really_extend) ?(shrlen = 16) n = {
-  o_s = String.create n;
+  o_s = Bytes.create n;
   o_max_len = n;
   o_len = 0;
   o_offs = 0;
@@ -83,26 +83,26 @@ let add_string b s =
 
 let add_char b c =
   let pos = alloc b 1 in
-  b.o_s.[pos] <- c
+  Bytes.set b.o_s pos c
 
 let unsafe_add_char b c =
   let len = b.o_len in
-  b.o_s.[len] <- c;
+  Bytes.set b.o_s len c;
   b.o_len <- len + 1
 
 let add_char2 b c1 c2 =
   let pos = alloc b 2 in
   let s = b.o_s in
-  String.unsafe_set s pos c1;
-  String.unsafe_set s (pos+1) c2
+  Bytes.unsafe_set s pos c1;
+  Bytes.unsafe_set s (pos+1) c2
 
 let add_char4 b c1 c2 c3 c4 =
   let pos = alloc b 4 in
   let s = b.o_s in
-  String.unsafe_set s pos c1;
-  String.unsafe_set s (pos+1) c2;
-  String.unsafe_set s (pos+2) c3;
-  String.unsafe_set s (pos+3) c4
+  Bytes.unsafe_set s pos c1;
+  Bytes.unsafe_set s (pos+1) c2;
+  Bytes.unsafe_set s (pos+2) c3;
+  Bytes.unsafe_set s (pos+3) c4
 
 
 
@@ -112,10 +112,10 @@ let clear b =
   Bi_share.Wr.clear b.o_shared
 
 let reset b =
-  if String.length b.o_s <> b.o_init_len then
-    b.o_s <- String.create b.o_init_len;
+  if Bytes.length b.o_s <> b.o_init_len then
+    b.o_s <- Bytes.create b.o_init_len;
   b.o_offs <- 0;
   b.o_len <- 0;
   b.o_shared <- Bi_share.Wr.create b.o_shared_init_len
 
-let contents b = String.sub b.o_s 0 b.o_len
+let contents b = Bytes.to_string (Bytes.sub b.o_s 0 b.o_len)
