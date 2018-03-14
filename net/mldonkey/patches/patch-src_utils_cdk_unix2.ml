$NetBSD: patch-src_utils_cdk_unix2.ml,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/cdk/unix2.ml~	2013-07-07 10:53:52.000000000 +0000
+++ src/utils/cdk/unix2.ml
@@ -156,7 +156,7 @@ let copy oldname newname =
       (try Unix.fchmod descr stats.Unix.LargeFile.st_perm 
        with e -> lprintf_nl "copy: failed to preserve mode"));
       let buffer_len = 8192 in
-      let buffer = String.create buffer_len in
+      let buffer = Bytes.create buffer_len in
       let rec copy_file () =
 	let n = input ic buffer 0 buffer_len in
 	if n = 0 then () else begin 
@@ -205,18 +205,18 @@ let rec remove_all_directory dirname =
   Unix.rmdir dirname
 
 let random () =
-  let s = String.create 7 in
+  let s = Bytes.create 7 in
   for i = 0 to 6 do
-    s.[i] <- char_of_int (97 + Random.int 26)
+    Bytes.set s i (char_of_int (97 + Random.int 26))
   done;
-  s
+  Bytes.to_string s
 
 let can_write_to_directory dirname =
   let temp_file = Filename.concat dirname "tmp_" ^ random () ^ "_mld.tmp" in
   let check () = with_remove temp_file (fun _ ->
     tryopen_openfile temp_file [O_WRONLY; O_CREAT] 0o600 (fun fd ->
       let test_string = "mldonkey accesstest - this file can be deleted\n" in
-      really_write fd test_string 0 (String.length test_string)))
+      really_write fd (Bytes.of_string test_string) 0 (String.length test_string)))
   in
   try
     check ()
