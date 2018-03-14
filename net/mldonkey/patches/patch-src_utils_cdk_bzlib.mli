$NetBSD: patch-src_utils_cdk_bzlib.mli,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/cdk/bzlib.mli~	2005-08-01 20:09:13.000000000 +0000
+++ src/utils/cdk/bzlib.mli
@@ -10,7 +10,7 @@ type action = BZ_RUN | BZ_FLUSH | BZ_FIN
 
 external compress_init: int -> int -> int -> stream = "camlzip_bzCompressInit"
 external compress:
-  stream -> string -> int -> int -> string -> int -> int -> action
+  stream -> string -> int -> int -> bytes -> int -> int -> action
          -> bool * int * int
   = "camlzip_bzCompress_bytecode" "camlzip_bzCompress"
 external compress_end: stream -> unit = "camlzip_bzCompressEnd"
@@ -18,7 +18,7 @@ external compress_end: stream -> unit = 
 
 external decompress_init: int -> bool -> stream = "camlzip_bzDecompressInit"
 external decompress:
-  stream -> string -> int -> int -> string -> int -> int -> bool * int * int
+  stream -> string -> int -> int -> bytes -> int -> int -> bool * int * int
   = "camlzip_bzDecompress_bytecode" "camlzip_bzDecompress"
 external decompress_end: stream -> unit = "camlzip_bzDecompressEnd"
 
