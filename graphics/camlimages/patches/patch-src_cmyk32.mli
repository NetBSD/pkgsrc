$NetBSD: patch-src_cmyk32.mli,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/cmyk32.mli~	2011-06-22 18:04:32.000000000 +0000
+++ src/cmyk32.mli
@@ -32,7 +32,7 @@ type t = {
 (* Please read the comments of IMAGE in genimage.mli *)
 
 val dump : t -> string;;
-val unsafe_access : t -> int -> int -> string * int;;
+val unsafe_access : t -> int -> int -> Bytes.t * int;;
 val get_strip : t -> int -> int -> int -> string;;
 val set_strip : t -> int -> int -> int -> string -> unit;;
 val get_scanline : t -> int -> string;;
