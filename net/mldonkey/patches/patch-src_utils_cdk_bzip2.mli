$NetBSD: patch-src_utils_cdk_bzip2.mli,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/cdk/bzip2.mli~	2005-09-13 09:49:40.000000000 +0000
+++ src/utils/cdk/bzip2.mli
@@ -22,7 +22,7 @@ val input_byte: in_channel -> int
         (* Same as [Bzip2.input_char], but return the 8-bit integer representing
            the character.
            Raise [End_of_file] if no more compressed data is available. *)
-val input: in_channel -> string -> int -> int -> int
+val input: in_channel -> bytes -> int -> int -> int
         (* [input ic buf pos len] uncompresses up to [len] characters
            from the given channel [ic],
            storing them in string [buf], starting at character number [pos].
@@ -38,7 +38,7 @@ val input: in_channel -> string -> int -
            exactly [len] characters.)
            Exception [Invalid_argument "Bzip2.input"] is raised if
            [pos] and [len] do not designate a valid substring of [buf]. *)
-val really_input: in_channel -> string -> int -> int -> unit
+val really_input: in_channel -> bytes -> int -> int -> unit
         (* [really_input ic buf pos len] uncompresses [len] characters
            from the given channel, storing them in
            string [buf], starting at character number [pos].
