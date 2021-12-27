$NetBSD: patch-src_ttfont.ml,v 1.1 2021/12/27 00:49:02 dholland Exp $

Hack up the code for immutable strings.

--- src/ttfont.ml~	2010-08-18 10:05:40.000000000 +0000
+++ src/ttfont.ml
@@ -57,7 +57,7 @@ let build face dpi pt unicode =
   let width = bitmapinfo.bitmap_width in
   let height = bitmapinfo.bitmap_height in
   let bitmap_len = (width * height + 7) / 8 in
-  let bitmap = String.create bitmap_len in
+  let bitmap = Bytes.create bitmap_len in
   let is_black pos =
     let x = pos mod width in
     let y = pos / width in
@@ -72,7 +72,7 @@ let build face dpi pt unicode =
 	if is_black !pos then char := !char lor 0x01;
 	incr pos
     done;
-    bitmap.[i] <- char_of_int !char
+    Bytes.set bitmap i (char_of_int !char)
   done;
   
   { code= unicode;
@@ -82,7 +82,7 @@ let build face dpi pt unicode =
     height= height;
     hoffset= -bitmapinfo.bitmap_left;
     voffset= bitmapinfo.bitmap_top;
-    bitmap= bitmap
+    bitmap= Bytes.to_string bitmap
   }	
 ;;
 
