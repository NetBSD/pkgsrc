$NetBSD: patch-src_utils_cdk_string2.mli,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/cdk/string2.mli~	2007-01-28 20:39:59.000000000 +0000
+++ src/utils/cdk/string2.mli
@@ -79,7 +79,9 @@ val subcontains : string -> string -> bo
 val of_char : char -> string
 (*d [of_char c] returns the string containing one [c]. *)
   
+(* problematic with immutable strings
 val resize : string -> int ->  string
+*)
 (*d [resize s len] returns a string of length [len] starting with [s]. *)
   
 val init : int -> (int -> char) -> string
@@ -93,7 +95,11 @@ external contains : string -> string -> 
 val starts_with : (* string *) string -> (* start *) string -> bool
 
 (* [replace_char s c1 c2] replaces char [c1] by char [c2] in [s] *)
+(* problematic with immutable strings
 val replace_char : string -> char -> char -> unit
+*)
+(* [replace_char' s c1 c2] makes a new string with [c1] replaced with [c2] *)
+val replace_char' : string -> char -> char -> string
 
 (* [stem s] cuts the string [s] in small words, for indexation eg *)
 val stem : string -> string list
