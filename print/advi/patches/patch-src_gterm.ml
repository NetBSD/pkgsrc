$NetBSD: patch-src_gterm.ml,v 1.1 2021/12/27 00:49:02 dholland Exp $

Hack up the code for immutable strings.

--- src/gterm.ml~	2007-01-18 14:14:36.000000000 +0000
+++ src/gterm.ml
@@ -28,7 +28,7 @@ type rectangle = GraphicsY11.rectangle =
 
 type term = {
   (* Character contents of the terminal. *)
-  mutable lines : string array;
+  mutable lines : Bytes.t array;
   (* Height in lines. *)
   mutable height : int;
   (* Width in characters. *)
@@ -71,7 +71,7 @@ let draw_cursor t cc cf =
   let gx = cursor_gx t
   and gy = cursor_gy t in 
   Graphics.fill_rect gx gy t.font_size_x t.font_size_y;
-  let c = t.lines.(t.cursor_y).[t.cursor_x] in
+  let c = Bytes.get t.lines.(t.cursor_y) t.cursor_x in
   Graphics.moveto gx gy;
   Graphics.set_color cf;
   Graphics.draw_char c;
@@ -147,7 +147,7 @@ let redraw t =
   Array.iteri
    (fun i s ->
       Graphics.moveto t.gx (t.gy + t.font_size_y * i);
-      Graphics.draw_string s)
+      Graphics.draw_string (Bytes.to_string s)) (* XXX: slow? *)
    t.lines;
   show_cursor t;;
 
@@ -156,7 +156,7 @@ let clear t =
   Graphics.fill_rect
     t.gx t.gy (t.width * t.font_size_x) (t.height * t.font_size_y);
   Graphics.set_color t.foreground_color;
-  Array.iter (fun s -> String.fill s 0 (String.length s) ' ') t.lines;
+  Array.iter (fun s -> Bytes.fill s 0 (Bytes.length s) ' ') t.lines;
   htab t 0;
   vtab t (t.height - 1);;
 
@@ -223,7 +223,7 @@ let make_term_gen fg bg bw bwc tc cc xc 
   if h < 1 || w < 1 || bw < 0 then failwith "make_term_gen" else
   let font_size_x, font_size_y = Graphics.text_size "M" in
   let t = {
-    lines = Array.init h (fun i -> String.make w ' ');
+    lines = Array.init h (fun i -> Bytes.make w ' ');
     height = h;
     width = w;
     gheight = h * font_size_y;
@@ -305,7 +305,7 @@ let make_term =
 (* Basic functions to edit. *)
 let end_of_line t =
   let line = t.lines.(t.cursor_y) in
-  let l = String.length line in
+  let l = Bytes.length line in
   htab t l;;
 
 let beginning_of_line t = htab t 0;;
