$NetBSD: patch-src_image__intf.mli,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/image_intf.mli.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/image_intf.mli
@@ -19,9 +19,9 @@ module type ENCODE =
   sig
     type t
     val bytes_per_pixel : int
-    val get : string -> int -> t
-    val set : string -> int -> t -> unit
-    val make : t -> string
+    val get : Bytes.t -> int -> t
+    val set : Bytes.t -> int -> t -> unit
+    val make : t -> Bytes.t
   end;;
 
 (** Low level image module type *)
@@ -33,15 +33,16 @@ module type RAWIMAGE = sig
   val width : t -> int
   val height : t -> int
   val dump : t -> string
+  val dumpbytes : t -> Bytes.t
   val create_with : int -> int -> string -> t
   val create_with_scanlines : int -> int -> string array -> t
   val create : int -> int -> t
   val make : int -> int -> elt -> t
-  val unsafe_access : t -> int -> int -> string * int
+  val unsafe_access : t -> int -> int -> Bytes.t * int
   val get_strip : t -> int -> int -> int -> string
   val set_strip : t -> int -> int -> int -> string -> unit
   val get_scanline : t -> int -> string
-  val get_scanline_ptr : t -> (int -> (string * int) * int) option
+  val get_scanline_ptr : t -> (int -> (Bytes.t * int) * int) option
   val set_scanline : t -> int -> string -> unit
   val unsafe_get : t -> int -> int -> elt
   val unsafe_set : t -> int -> int -> elt -> unit
@@ -126,11 +127,12 @@ module type IMAGE = sig
 
   (** functions for internal use *)
   val dump : t -> string
-  val unsafe_access : t -> int -> int -> string * int
+  val dumpbytes : t -> Bytes.t
+  val unsafe_access : t -> int -> int -> Bytes.t * int
   val get_strip : t -> int -> int -> int -> string
   val set_strip : t -> int -> int -> int -> string -> unit
   val get_scanline : t -> int -> string
-  val get_scanline_ptr : t -> (int -> (string * int) * int) option
+  val get_scanline_ptr : t -> (int -> (Bytes.t * int) * int) option
   val set_scanline : t -> int -> string -> unit
   val blocks : t -> int * int
   val dump_block : t -> int -> int -> Bitmap.Block.t
