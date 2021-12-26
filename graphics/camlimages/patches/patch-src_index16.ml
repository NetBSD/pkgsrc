$NetBSD: patch-src_index16.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/index16.ml.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/index16.ml
@@ -19,13 +19,13 @@ module E = struct
   type t = int
   let bytes_per_pixel = 2
   let get str pos =
-    int_of_char str.[pos    ] * 256 +
-    int_of_char str.[pos + 1]
+    int_of_char (Bytes.get str (pos    )) * 256 +
+    int_of_char (Bytes.get str (pos + 1))
   let set str pos t =
-    str.[pos    ] <- char_of_int (t / 256);
-    str.[pos + 1] <- char_of_int (t mod 256)
+    Bytes.set str (pos    ) (char_of_int (t / 256));
+    Bytes.set str (pos + 1) (char_of_int (t mod 256))
   let make t =
-    let str = String.create bytes_per_pixel in
+    let str = Bytes.create bytes_per_pixel in
     set str 0 t;
     str
 end;;
