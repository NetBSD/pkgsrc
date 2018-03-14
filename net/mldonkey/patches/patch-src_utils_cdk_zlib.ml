$NetBSD: patch-src_utils_cdk_zlib.ml,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/cdk/zlib.mli~	2005-08-01 20:09:13.000000000 +0000
+++ src/utils/cdk/zlib.mli
@@ -2,10 +2,10 @@ exception Error of string * string
 
 val compress:
   ?level: int -> ?header: bool -> 
-  (string -> int) -> (string -> int -> unit) -> unit
+  (bytes -> int) -> (bytes -> int -> unit) -> unit
 
 val uncompress:
-  ?header: bool -> (string -> int) -> (string -> int -> unit) -> unit
+  ?header: bool -> (bytes -> int) -> (bytes -> int -> unit) -> unit
 
 type stream
 
@@ -17,14 +17,14 @@ type flush_command =
 
 external deflate_init: int -> bool -> stream = "camlzip_deflateInit"
 external deflate:
-  stream -> string -> int -> int -> string -> int -> int -> flush_command
+  stream -> bytes -> int -> int -> bytes -> int -> int -> flush_command
          -> bool * int * int
   = "camlzip_deflate_bytecode" "camlzip_deflate"
 external deflate_end: stream -> unit = "camlzip_deflateEnd"
 
 external inflate_init: bool -> stream = "camlzip_inflateInit"
 external inflate:
-  stream -> string -> int -> int -> string -> int -> int -> flush_command
+  stream -> bytes -> int -> int -> bytes -> int -> int -> flush_command
          -> bool * int * int
   = "camlzip_inflate_bytecode" "camlzip_inflate"
 external inflate_end: stream -> unit = "camlzip_inflateEnd"
@@ -33,8 +33,8 @@ external update_crc: int32 -> string -> 
                    = "camlzip_update_crc32"
 
 val uncompress_string : string -> string
-val uncompress_string2 : string -> string
-val compress_string : ?level:int -> string -> string
+val uncompress_string2 : bytes -> bytes
+val compress_string : ?level:int -> bytes -> bytes
 val gzip_string : ?level:int -> string -> string
 
 val zlib_version_num : unit -> string
