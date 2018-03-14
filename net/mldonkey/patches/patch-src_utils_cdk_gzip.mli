$NetBSD: patch-src_utils_cdk_gzip.mli,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/cdk/gzip.mli~	2010-11-07 15:01:40.000000000 +0000
+++ src/utils/cdk/gzip.mli
@@ -35,7 +35,7 @@ val input_byte: in_channel -> int
         (* Same as [Gzip.input_char], but return the 8-bit integer representing
            the character.
            Raise [End_of_file] if no more compressed data is available. *)
-val input: in_channel -> string -> int -> int -> int
+val input: in_channel -> bytes -> int -> int -> int
         (* [input ic buf pos len] uncompresses up to [len] characters
            from the given channel [ic],
            storing them in string [buf], starting at character number [pos].
@@ -51,7 +51,7 @@ val input: in_channel -> string -> int -
            exactly [len] characters.)
            Exception [Invalid_argument "Gzip.input"] is raised if
            [pos] and [len] do not designate a valid substring of [buf]. *)
-val really_input: in_channel -> string -> int -> int -> unit
+val really_input: in_channel -> bytes -> int -> int -> unit
         (* [really_input ic buf pos len] uncompresses [len] characters
            from the given channel, storing them in
            string [buf], starting at character number [pos].
@@ -95,7 +95,7 @@ val output_char: 'a out_channel -> char 
 val output_byte: 'a out_channel -> int -> unit
         (* Same as [Gzip.output_char], but the output character is given
            by its code.  The given integer is taken modulo 256. *)
-val output: 'a out_channel -> string -> int -> int -> unit
+val output: 'a out_channel -> bytes -> int -> int -> unit
         (* [output oc buf pos len] compresses and writes [len] characters
            from string [buf], starting at offset [pos], and writes the
            compressed data to the channel [oc].
