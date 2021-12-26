$NetBSD: patch-src_rgba32.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/rgba32.ml.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/rgba32.ml
@@ -20,17 +20,17 @@ module E = struct
   let bytes_per_pixel = 4
   let get str pos =
     { color =
-        { r = int_of_char str.[pos    ];
-          g = int_of_char str.[pos + 1];
-          b = int_of_char str.[pos + 2] };
-      alpha = int_of_char str.[pos + 3] }
+        { r = int_of_char (Bytes.get str (pos    ));
+          g = int_of_char (Bytes.get str (pos + 1));
+          b = int_of_char (Bytes.get str (pos + 2)) };
+      alpha = int_of_char (Bytes.get str (pos + 3)) }
   let set str pos t =
-    str.[pos    ] <- char_of_int t.color.r;
-    str.[pos + 1] <- char_of_int t.color.g;
-    str.[pos + 2] <- char_of_int t.color.b;
-    str.[pos + 3] <- char_of_int t.alpha
+    Bytes.set str (pos    ) (char_of_int t.color.r);
+    Bytes.set str (pos + 1) (char_of_int t.color.g);
+    Bytes.set str (pos + 2) (char_of_int t.color.b);
+    Bytes.set str (pos + 3) (char_of_int t.alpha)
   let make t =
-    let str = String.create bytes_per_pixel in
+    let str = Bytes.create bytes_per_pixel in
     set str 0 t;
     str
 end;;
