$NetBSD: patch-src_index8.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/index8.ml.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/index8.ml
@@ -19,11 +19,11 @@ module E = struct
   type t = int
   let bytes_per_pixel = 1
   let get str pos =
-    int_of_char str.[pos]
+    int_of_char (Bytes.get str pos)
   let set str pos t =
-    str.[pos] <- char_of_int t
+    Bytes.set str pos (char_of_int t)
   let make t =
-    let str = String.create bytes_per_pixel in
+    let str = Bytes.create bytes_per_pixel in
     set str 0 t;
     str
 end;;
@@ -87,6 +87,7 @@ let rawimage = C.rawimage;;
 let create = IMAGE.create;;
 let make = IMAGE.make;;
 let dump = IMAGE.dump;;
+let dumpbytes = IMAGE.dumpbytes;;
 let unsafe_access = IMAGE.unsafe_access;;
 let get_strip = IMAGE.get_strip;;
 let set_strip = IMAGE.set_strip;;
