$NetBSD: patch-src_utils_lib_url.ml,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/lib/url.ml~	2009-02-24 18:38:34.000000000 +0000
+++ src/utils/lib/url.ml
@@ -36,21 +36,21 @@ type url = {
 let encode s =
   let pos = ref 0 in
   let len = String.length s in
-  let res = String.create (3*len) in
+  let res = Bytes.create (3*len) in
   let hexa_digit x =
     if x >= 10 then Char.chr (Char.code 'A' + x - 10)
     else Char.chr (Char.code '0' + x) in
   for i=0 to len-1 do
     match s.[i] with
     | 'a'..'z' | 'A'..'Z' | '0'..'9' | '.' | '-' | '*' | '_' | '\''| '(' | ')'->
-        res.[!pos] <- s.[i]; incr pos
+        Bytes.set res !pos s.[i]; incr pos
     | c ->
-        res.[!pos] <- '%';
-        res.[!pos+1] <- hexa_digit (Char.code c / 16);
-        res.[!pos+2] <- hexa_digit (Char.code c mod 16);
+        Bytes.set res !pos '%';
+        Bytes.set res (!pos+1) (hexa_digit (Char.code c / 16));
+        Bytes.set res (!pos+2) (hexa_digit (Char.code c mod 16));
         pos := !pos + 3
   done;
-  String.sub res 0 !pos
+  Bytes.to_string (Bytes.sub res 0 !pos)
 
 (** decodes a sting according RFC 1738
 or x-www-form-urlencoded ('+' with ' ')
