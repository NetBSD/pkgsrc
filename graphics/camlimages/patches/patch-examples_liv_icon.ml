$NetBSD: patch-examples_liv_icon.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Use "Stdlib" instead of "Pervasives".

--- examples/liv/icon.ml~	2011-06-22 18:04:32.000000000 +0000
+++ examples/liv/icon.ml
@@ -98,8 +98,8 @@ let create_livthumb name =
       | Rgb24 i -> i
       | _ -> assert false in
     img#resize None
-      (Pervasives.truncate (float w *. ratio))
-      (Pervasives.truncate (float h *. ratio)) in
+      (Stdlib.truncate (float w *. ratio))
+      (Stdlib.truncate (float h *. ratio)) in
   img#save thumbpath (Some Jpeg) [Save_Quality 75];
   img#destroy;;
 
