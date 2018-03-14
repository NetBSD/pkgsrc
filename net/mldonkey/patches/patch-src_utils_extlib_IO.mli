$NetBSD: patch-src_utils_extlib_IO.mli,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/extlib/IO.mli~	2010-11-07 15:01:40.000000000 +0000
+++ src/utils/extlib/IO.mli
@@ -59,14 +59,14 @@ val really_nread : input -> int -> strin
   from the input. Raises [No_more_input] if at least [n] characters are
   not available. Raises [Invalid_argument] if [n] < 0. *)
 
-val input : input -> string -> int -> int -> int
+val input : input -> bytes -> int -> int -> int
 (** [input i s p l] reads up to [l] characters from the given input, storing
   them in string [s], starting at character number [p]. It returns the actual
   number of characters read or raise [No_more_input] if no character can be
   read. It will raise [Invalid_argument] if [p] and [l] do not designate a
   valid substring of [s]. *)
 
-val really_input : input -> string -> int -> int -> int
+val really_input : input -> bytes -> int -> int -> int
 (** [really_input i s p l] reads exactly [l] characters from the given input,
   storing them in the string [s], starting at position [p]. For consistency with
   {!IO.input} it returns [l]. Raises [No_more_input] if at [l] characters are
@@ -126,7 +126,7 @@ val output_enum : unit -> char Enum.t ou
 
 val create_in :
   read:(unit -> char) ->
-  input:(string -> int -> int -> int) -> close:(unit -> unit) -> input
+  input:(bytes -> int -> int -> int) -> close:(unit -> unit) -> input
 (** Fully create an input by giving all the needed functions. *)
 
 val create_out :
@@ -293,7 +293,7 @@ val drop_bits : in_bits -> unit
 
 class in_channel : input ->
   object
-	method input : string -> int -> int -> int
+	method input : bytes -> int -> int -> int
 	method close_in : unit -> unit
   end
 
