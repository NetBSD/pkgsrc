$NetBSD: patch-src_bitmap.mli,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/bitmap.mli.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/bitmap.mli
@@ -79,7 +79,7 @@ module Make(B:Bitdepth) : sig
   val destroy : t -> unit
     (* Destroy bitmaps *)
 
-  val access : t -> int -> int -> string * int
+  val access : t -> int -> int -> Bytes.t * int
 
   val get_strip : t -> int -> int -> int -> string
   val set_strip : t -> int -> int -> int -> string -> unit
@@ -100,8 +100,9 @@ module Make(B:Bitdepth) : sig
     *)
 
   (* only for one row *)      
-  val get_scanline_ptr : t -> (int -> (string * int) * int) option
+  val get_scanline_ptr : t -> (int -> (Bytes.t * int) * int) option
 
+  val dumpbytes : t -> Bytes.t
   val dump : t -> string
     (* Create a string representation of a bitmap. It may easily raise
        an exception Out_of_memory for large images. *)
