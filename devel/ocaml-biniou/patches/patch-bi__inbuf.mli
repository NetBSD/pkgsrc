$NetBSD: patch-bi__inbuf.mli,v 1.1 2018/03/11 02:30:34 dholland Exp $

Fix up mutable strings to make it build with ocaml 4.06.

--- bi_inbuf.mli~	2017-05-04 17:38:05.000000000 +0000
+++ bi_inbuf.mli
@@ -1,7 +1,7 @@
 (** Input buffer *)
 
 type t = {
-  mutable i_s : string;
+  mutable i_s : bytes;
     (** This is the buffer string.
        It can be accessed for reading but should normally only
        be written to or replaced only by the [i_refill] function.
@@ -92,9 +92,17 @@ val peek : t -> char
     @raise End_of_input if the end of input has already been reached.
   *)
 
+val from_bytes : ?pos:int -> ?shrlen:int -> bytes -> t
+  (**
+     Create an input buffer from a byte buffer.
+     @param pos     position to start from. Default: 0.
+     @param shrlen  initial length of the table used to store shared values.
+  *)
+
 val from_string : ?pos:int -> ?shrlen:int -> string -> t
   (**
      Create an input buffer from a string.
+     The string is copied into the internal buffer.
      @param pos     position to start from. Default: 0.
      @param shrlen  initial length of the table used to store shared values.
   *)
