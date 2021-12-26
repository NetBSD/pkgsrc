$NetBSD: patch-src_rgb24.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/rgb24.ml.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/rgb24.ml
@@ -19,15 +19,15 @@ module E = struct
   type t = Color.rgb
   let bytes_per_pixel = 3
   let get str pos =
-    { r = int_of_char str.[pos    ];
-      g = int_of_char str.[pos + 1];
-      b = int_of_char str.[pos + 2] }
+    { r = int_of_char (Bytes.get str (pos    ));
+      g = int_of_char (Bytes.get str (pos + 1));
+      b = int_of_char (Bytes.get str (pos + 2)) }
   let set str pos t =
-    str.[pos    ] <- char_of_int t.r;
-    str.[pos + 1] <- char_of_int t.g;
-    str.[pos + 2] <- char_of_int t.b
+    Bytes.set str (pos    ) (char_of_int t.r);
+    Bytes.set str (pos + 1) (char_of_int t.g);
+    Bytes.set str (pos + 2) (char_of_int t.b)
   let make t =
-    let str = String.create bytes_per_pixel in
+    let str = Bytes.create bytes_per_pixel in
     set str 0 t;
     str
 end
@@ -79,6 +79,7 @@ let rawimage = C.rawimage;;
 let create = IMAGE.create;;
 let make = IMAGE.make;;
 let dump = IMAGE.dump;;
+let dumpbytes = IMAGE.dumpbytes;;
 let unsafe_access = IMAGE.unsafe_access;;
 let get_strip = IMAGE.get_strip;;
 let set_strip = IMAGE.set_strip;;
