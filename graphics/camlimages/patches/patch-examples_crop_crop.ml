$NetBSD: patch-examples_crop_crop.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- examples/crop/crop.ml~	2011-06-22 18:04:32.000000000 +0000
+++ examples/crop/crop.ml
@@ -46,7 +46,7 @@ let edge edgename img24 =
     match edgename with
     | Some _ ->
         Some (new rgb24_with img24#width img24#height
-                [] (String.copy img24#dump))
+                [] img24#dump)
     | None -> None in
   let edge = Array.init img24#width (fun _ -> Array.create img24#height 0) in
 
