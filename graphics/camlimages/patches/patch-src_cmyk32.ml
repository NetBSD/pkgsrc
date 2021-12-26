$NetBSD: patch-src_cmyk32.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/cmyk32.ml.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/cmyk32.ml
@@ -21,17 +21,17 @@ module E = struct
   type t = Color.cmyk
   let bytes_per_pixel = 4
   let get str pos =
-    { c = int_of_char str.[pos    ];
-      m = int_of_char str.[pos + 1];
-      y = int_of_char str.[pos + 2];
-      k = int_of_char str.[pos + 3]; }
+    { c = int_of_char (Bytes.get str (pos    ));
+      m = int_of_char (Bytes.get str (pos + 1));
+      y = int_of_char (Bytes.get str (pos + 2));
+      k = int_of_char (Bytes.get str (pos + 3)); }
   let set str pos t =
-    str.[pos    ] <- char_of_int t.c;
-    str.[pos + 1] <- char_of_int t.m;
-    str.[pos + 2] <- char_of_int t.y;
-    str.[pos + 3] <- char_of_int t.k
+    Bytes.set str (pos    ) (char_of_int t.c);
+    Bytes.set str (pos + 1) (char_of_int t.m);
+    Bytes.set str (pos + 2) (char_of_int t.y);
+    Bytes.set str (pos + 3) (char_of_int t.k)
   let make t =
-    let str = String.create bytes_per_pixel in
+    let str = Bytes.create bytes_per_pixel in
     set str 0 t;
     str
 end;;
