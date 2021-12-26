$NetBSD: patch-src_rgba32.mli,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/rgba32.mli~	2011-06-22 18:04:32.000000000 +0000
+++ src/rgba32.mli
@@ -37,7 +37,7 @@ val resize : (float -> unit) option -> t
 (** Please read the comments of module [IMAGE] in file [genimage.mli]. *)
 
 val dump : t -> string;;
-val unsafe_access : t -> int -> int -> string * int;;
+val unsafe_access : t -> int -> int -> Bytes.t * int;;
 val get_strip : t -> int -> int -> int -> string;;
 val set_strip : t -> int -> int -> int -> string -> unit;;
 val get_scanline : t -> int -> string;;
