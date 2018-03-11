$NetBSD: patch-bi__stream.ml,v 1.1 2018/03/11 02:30:34 dholland Exp $

Fix up mutable strings to make it build with ocaml 4.06.

--- bi_stream.ml~	2017-05-04 17:38:05.000000000 +0000
+++ bi_stream.ml
@@ -53,9 +53,9 @@ let rec read_chunk of_string ic =
           error
             (sprintf
                "Corrupted stream: excessive chunk length (%i bytes)" len);
-        let s = String.create len in
+        let s = Bytes.create len in
         really_input ic s 0 len;
-        Some (of_string s)
+        Some (of_string (Bytes.to_string s))
 
     | '\000' -> None
 
