$NetBSD: patch-src_index8.mli,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/index8.mli~	2011-06-22 18:04:32.000000000 +0000
+++ src/index8.mli
@@ -40,7 +40,8 @@ val to_rgba32 : ?failsafe: Color.rgba ->
 (** Please read the comments of IMAGEINDEXED in genimage.mli *)
 
 val dump : t -> string;;
-val unsafe_access : t -> int -> int -> string * int;;
+val dumpbytes : t -> Bytes.t;;
+val unsafe_access : t -> int -> int -> Bytes.t * int;;
 val get_strip : t -> int -> int -> int -> string;;
 val set_strip : t -> int -> int -> int -> string -> unit;;
 val get_scanline : t -> int -> string;;
