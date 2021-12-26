$NetBSD: patch-src_tiff.mli,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/tiff.mli~	2011-06-22 18:04:32.000000000 +0000
+++ src/tiff.mli
@@ -31,7 +31,7 @@ type colormodel = RGB | CMYK | WHITEBLAC
 type in_handle;;
 
 val open_in : string -> int * int * float * colormodel * in_handle;;
-val read_scanline : in_handle -> string -> int -> unit;;
+val read_scanline : in_handle -> Bytes.t -> int -> unit;;
 val close_in : in_handle -> unit;;
 
 type out_handle;;
