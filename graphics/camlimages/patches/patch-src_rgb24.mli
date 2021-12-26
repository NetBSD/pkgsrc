$NetBSD: patch-src_rgb24.mli,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/rgb24.mli.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/rgb24.mli
@@ -53,7 +53,7 @@ val unsafe_set : t -> int -> int -> elt 
 val get_strip : t -> int -> int -> int -> string;;
 val set_strip : t -> int -> int -> int -> string -> unit;;
 val get_scanline : t -> int -> string;;
-val get_scanline_ptr : t -> (int -> (string * int) * int) option;;
+val get_scanline_ptr : t -> (int -> (Bytes.t * int) * int) option;;
 val set_scanline : t -> int -> string -> unit;;
 val blit : t -> int -> int -> t -> int -> int -> int -> int -> unit;;
 val map : (elt -> elt -> elt) ->
@@ -64,4 +64,5 @@ val dump_block : t -> int -> int -> Bitm
 val copy : t -> t;;
 val sub : t -> int -> int -> int -> int -> t;;
 val dump : t -> string;;
-val unsafe_access : t -> int -> int -> string * int;;
+val dumpbytes : t -> Bytes.t;;
+val unsafe_access : t -> int -> int -> Bytes.t * int;;
