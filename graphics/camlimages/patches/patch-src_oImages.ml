$NetBSD: patch-src_oImages.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/oImages.ml~	2011-06-22 18:04:32.000000000 +0000
+++ src/oImages.ml
@@ -36,7 +36,7 @@ class type ['a] map = object
   method unsafe_set : int -> int -> 'a -> unit
   method get : int -> int -> 'a
   method set : int -> int -> 'a -> unit
-  method unsafe_access : int -> int -> string * int
+  method unsafe_access : int -> int -> Bytes.t * int
 end;;
 
 class type oimage = object
