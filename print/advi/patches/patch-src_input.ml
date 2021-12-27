$NetBSD: patch-src_input.ml,v 1.1 2021/12/27 00:49:02 dholland Exp $

Hack up the code for immutable strings.

--- src/input.ml~	2007-01-18 14:14:36.000000000 +0000
+++ src/input.ml
@@ -84,9 +84,9 @@ let input_int32 =
 	(Printf.sprintf "Pkfont: cannot work on a %d-bit architecture" size) ;;
 
 let input_string ch n =
-  let str = String.create n in
+  let str = Bytes.create n in
   really_input ch str 0 n ;
-  str ;;
+  Bytes.to_string str ;;
 
 let skip_bytes ch n =
   seek_in ch (pos_in ch + n) ;;
