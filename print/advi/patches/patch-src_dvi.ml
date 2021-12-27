$NetBSD: patch-src_dvi.ml,v 1.1 2021/12/27 00:49:02 dholland Exp $

Hack up the code for immutable strings.

--- src/dvi.ml~	2010-04-05 08:15:06.000000000 +0000
+++ src/dvi.ml
@@ -363,9 +363,9 @@ let input_int32 =
   | _ -> assert false;;
 
 let input_string ch len =
-  let str = String.create len in
+  let str = Bytes.create len in
   really_input ch str 0 len ;
-  str;;
+  Bytes.to_string str;;
 
 (*** Parsing commands ***)
 
