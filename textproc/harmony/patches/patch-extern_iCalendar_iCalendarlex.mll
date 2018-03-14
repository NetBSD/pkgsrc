$NetBSD: patch-extern_iCalendar_iCalendarlex.mll,v 1.1 2018/03/14 06:27:21 dholland Exp $

Fix build with ocaml 4.06.

--- extern/iCalendar/iCalendarlex.mll~	2006-05-21 19:17:46.000000000 +0000
+++ extern/iCalendar/iCalendarlex.mll
@@ -11,7 +11,7 @@
 (* To buffer string literals *)
 
 let string_start_pos = ref 0;;
-let initial_string_buffer = String.create 256
+let initial_string_buffer = Bytes.create 256
 let string_buff = ref initial_string_buffer
 let string_index = ref 0
 
@@ -20,32 +20,32 @@ let reset_string_buffer () =
   string_index := 0
 
 let store_string_char c =
-  if !string_index >= String.length (!string_buff) then begin
-    let new_buff = String.create (String.length (!string_buff) * 2) in
-      String.blit (!string_buff) 0 new_buff 0 (String.length (!string_buff));
+  if !string_index >= Bytes.length (!string_buff) then begin
+    let new_buff = Bytes.create (Bytes.length (!string_buff) * 2) in
+      Bytes.blit (!string_buff) 0 new_buff 0 (Bytes.length (!string_buff));
       string_buff := new_buff
   end;
-  String.unsafe_set (!string_buff) (!string_index) c;
+  Bytes.unsafe_set (!string_buff) (!string_index) c;
   incr string_index
 
 let store_string s =
   let l = String.length s in
-  if !string_index + l > String.length (!string_buff) then begin
-    let new_buff = String.create ((String.length (!string_buff) + l) * 2) in
-      String.blit (!string_buff) 0 new_buff 0 (String.length (!string_buff));
+  if !string_index + l > Bytes.length (!string_buff) then begin
+    let new_buff = Bytes.create ((Bytes.length (!string_buff) + l) * 2) in
+      Bytes.blit (!string_buff) 0 new_buff 0 (Bytes.length (!string_buff));
       string_buff := new_buff
   end;
   String.blit s 0 (!string_buff) (!string_index) l;
   string_index := (!string_index) + l
 
 let get_stored_string () =
-  let s = String.sub (!string_buff) 0 (!string_index) in
+  let s = Bytes.sub (!string_buff) 0 (!string_index) in
   string_buff := initial_string_buffer;
   (*
   print_endline s;
   flush stdout;
   *)
-  s
+  Bytes.to_string s
 }
 
 let eol = "\r\n" | "\n"
