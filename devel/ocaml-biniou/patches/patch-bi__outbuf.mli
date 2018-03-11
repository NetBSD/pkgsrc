$NetBSD: patch-bi__outbuf.mli,v 1.1 2018/03/11 02:30:34 dholland Exp $

Fix up mutable strings to make it build with ocaml 4.06.

--- bi_outbuf.mli~	2017-05-04 17:38:05.000000000 +0000
+++ bi_outbuf.mli
@@ -1,7 +1,7 @@
 (** Output buffer *)
 
 type t = {
-  mutable o_s : string;
+  mutable o_s : bytes;
     (** Buffer string *)
 
   mutable o_max_len : int;
@@ -68,7 +68,7 @@ val flush_channel_writer : t -> unit
   *)
 
 val create_output_writer :
-  ?len:int -> ?shrlen:int -> < output : string -> int -> int -> int; .. > -> t
+  ?len:int -> ?shrlen:int -> < output : bytes -> int -> int -> int; .. > -> t
 val flush_output_writer : t -> unit
   (**
      Pair of convenience functions for creating a buffer that
