$NetBSD: patch-extern_iCalendar_iCalendar.ml,v 1.1 2018/03/14 06:27:21 dholland Exp $

Fix build with ocaml 4.06.

--- extern/iCalendar/iCalendar.ml~	2006-05-21 19:17:46.000000000 +0000
+++ extern/iCalendar/iCalendar.ml
@@ -1,13 +1,13 @@
 let read get_char =
   let lex_func s n =
-    let l = String.length s in
+    let l = Bytes.length s in
     let cur_pos = ref 0 in
     let nb_chars () = !cur_pos in
     let should_stop () = (n - !cur_pos) < 3 in (* enough to put \r\n c*)
     let store_string_char c =
       if !cur_pos >= l then failwith "string given by lexbuf is too short !"
       else begin
-        String.unsafe_set s (!cur_pos) c;
+        Bytes.unsafe_set s (!cur_pos) c;
         incr cur_pos
       end
     in
@@ -102,9 +102,9 @@ let chars_from_str inc =
 
 let read_file inc =
   let len = in_channel_length inc in
-  let buf = String.create len in
+  let buf = Bytes.create len in
   really_input inc buf 0 len;
-  buf
+  Bytes.to_string buf
 
 let iCalReader inc outc =
   let s = V.string_of_t (Ical.view_from_icalendar (read (chars_from_str inc))) in
