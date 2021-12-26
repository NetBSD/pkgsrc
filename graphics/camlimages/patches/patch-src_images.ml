$NetBSD: patch-src_images.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Silence nuisance warning about lowercase.

--- src/images.ml~	2011-06-22 18:04:32.000000000 +0000
+++ src/images.ml
@@ -102,7 +102,7 @@ let get_extension s =
   | _ -> s, "";;
 
 let guess_extension s =
-  let s = String.lowercase s in
+  let s = String.lowercase_ascii s in
   match s with
   | "gif" -> Gif
   | "bmp" -> Bmp
