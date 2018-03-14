$NetBSD: patch-src_utils_lib_misc.ml,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/lib/misc.ml~	2008-03-31 07:58:17.000000000 +0000
+++ src/utils/lib/misc.ml
@@ -92,13 +92,13 @@ let zip_create zipfile files =
 let gz_extract filename =
   let file = ref "" in
   try
-    let buffer = String.create 4096 in
+    let buffer = Bytes.create 4096 in
     let file_out = Filename2.temp_file "arch_" ".tmp" in
     file := file_out;
     Unix2.tryopen_read_gzip filename (fun ic ->
       Unix2.tryopen_write_bin file_out (fun oc ->
 	let rec decompress () =
-	  let n = Gzip.input ic buffer 0 (String.length buffer) in
+	  let n = Gzip.input ic buffer 0 (Bytes.length buffer) in
           if n = 0 then ()
 	  else
 	    begin
