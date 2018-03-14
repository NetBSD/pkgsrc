$NetBSD: patch-bytearray.mli,v 1.1 2018/03/14 10:16:03 dholland Exp $

Fix build with ocaml 4.06.

--- bytearray.mli~	2009-05-29 14:00:18.000000000 +0000
+++ bytearray.mli
@@ -16,7 +16,9 @@ val sub : t -> int -> int -> string
 
 val blit_from_string : string -> int -> t -> int -> int -> unit
 
-val blit_to_string : t -> int -> string -> int -> int -> unit
+val blit_from_bytes : bytes -> int -> t -> int -> int -> unit
+
+val blit_to_bytes : t -> int -> bytes -> int -> int -> unit
 
 val prefix : t -> t -> int -> bool
 
