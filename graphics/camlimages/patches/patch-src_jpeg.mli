$NetBSD: patch-src_jpeg.mli,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/jpeg.mli~	2011-06-22 18:04:32.000000000 +0000
+++ src/jpeg.mli
@@ -37,7 +37,7 @@ type in_handle;;
 val open_in : string -> int * int * in_handle;;
 val open_in_thumbnail :
   string -> Geometry.spec -> int * int * (int * int * in_handle);;
-val read_scanline : in_handle -> string -> int -> unit;;
+val read_scanline : in_handle -> Bytes.t -> int -> unit;;
 val close_in : in_handle -> unit;;
   
 type out_handle;;
