$NetBSD: patch-bi__inbuf.ml,v 1.1 2018/03/11 02:30:34 dholland Exp $

Fix up mutable strings to make it build with ocaml 4.06.

--- bi_inbuf.ml~	2017-05-04 17:38:05.000000000 +0000
+++ bi_inbuf.ml
@@ -1,5 +1,5 @@
 type t = {
-  mutable i_s : string;
+  mutable i_s : bytes;
   mutable i_pos : int;
   mutable i_len : int;
   mutable i_offs : int;
@@ -35,14 +35,14 @@ let read ib n =
 let read_char ib =
   let pos = ib.i_pos in
   if ib.i_len - pos > 0 then (
-    let c = String.unsafe_get ib.i_s pos in
+    let c = Bytes.unsafe_get ib.i_s pos in
     ib.i_pos <- pos + 1;
     c
   )
   else
     if try_preread ib 1 > 0 then
       let pos = ib.i_pos in
-      let c = String.unsafe_get ib.i_s pos in
+      let c = Bytes.unsafe_get ib.i_s pos in
       ib.i_pos <- pos + 1;
       c
     else
@@ -51,24 +51,27 @@ let read_char ib =
 let peek ib =
   let pos = ib.i_pos in
   if ib.i_len - pos > 0 then (
-    String.unsafe_get ib.i_s pos
+    Bytes.unsafe_get ib.i_s pos
   )
   else
     if try_preread ib 1 > 0 then
-      String.unsafe_get ib.i_s ib.i_pos
+      Bytes.unsafe_get ib.i_s ib.i_pos
     else
       raise End_of_input
 
-let from_string ?(pos = 0) ?(shrlen = 16) s = {
+let from_bytes ?(pos = 0) ?(shrlen = 16) s = {
   i_s = s;
   i_pos = pos;
-  i_len = String.length s;
+  i_len = Bytes.length s;
   i_offs = -pos;
-  i_max_len = String.length s;
+  i_max_len = Bytes.length s;
   i_refill = (fun ib n -> ());
   i_shared = Bi_share.Rd.create shrlen;
 }
 
+let from_string ?(pos = 0) ?(shrlen = 16) s =
+  from_bytes ~pos ~shrlen (Bytes.of_string s)
+
 (*
   Like Pervasives.really_input but returns the number of bytes
   read instead of raising End_of_file when the end of file is reached.
@@ -87,7 +90,7 @@ let refill_from_channel ic ib n =
     let rem_len = ib.i_len - ib.i_pos in
     if rem_len < n then
       let s = ib.i_s in
-      String.blit s ib.i_pos s 0 rem_len;
+      Bytes.blit s ib.i_pos s 0 rem_len;
       let to_read = n - rem_len in
       let really_read = not_really_input ic s rem_len to_read 0 in
       ib.i_offs <- ib.i_offs + ib.i_pos;
@@ -96,7 +99,7 @@ let refill_from_channel ic ib n =
   )
 
 let from_channel ?(len = 4096) ?(shrlen = 16) ic = {
-  i_s = String.create len;
+  i_s = Bytes.create len;
   i_pos = 0;
   i_len = 0;
   i_offs = 0;
