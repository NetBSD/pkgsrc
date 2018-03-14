$NetBSD: patch-src_utils_lib_unix32.mli,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/lib/unix32.mli~	2011-01-31 17:17:07.000000000 +0000
+++ src/utils/lib/unix32.mli
@@ -54,11 +54,11 @@ val flush : unit -> unit
 val flush_fd : t -> unit
 val buffered_write : t -> int64 -> string -> int -> int -> unit
 val buffered_write_copy : t -> int64 -> string -> int -> int -> unit
-val write : t -> int64 -> string -> int -> int -> unit
+val write : t -> int64 -> bytes -> int -> int -> unit
 val max_buffered : int64 ref
 val remove : t -> unit
   
-val read : t -> int64 -> string -> int -> int -> unit
+val read : t -> int64 -> bytes -> int -> int -> unit
 (*val allocate_chunk :  t -> int64 -> int -> unit*)
   
 val copy_chunk : t -> t -> int64 -> int64 -> int -> unit
