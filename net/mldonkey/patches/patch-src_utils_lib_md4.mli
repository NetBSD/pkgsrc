$NetBSD: patch-src_utils_lib_md4.mli,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/lib/md4.mli~	2004-08-04 16:59:27.000000000 +0000
+++ src/utils/lib/md4.mli
@@ -49,7 +49,7 @@ module type Digest = sig
     
     val string : string -> t
 (*    val file : string -> t *)
-    val create : unit -> t
+    val create : unit -> bytes
     val direct_of_string : string -> t
     val direct_to_string : t -> string
     val random : unit -> t
@@ -58,7 +58,7 @@ module type Digest = sig
     
     val option : t Options.option_class
     
-    val xor : t -> t -> t
+    val xor : t -> t -> bytes
     val value_to_hash : Options.option_value -> t
     val hash_to_value : t -> Options.option_value
 
