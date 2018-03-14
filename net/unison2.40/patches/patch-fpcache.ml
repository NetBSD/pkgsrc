$NetBSD: patch-fpcache.ml,v 1.1 2018/03/14 11:16:15 dholland Exp $

Fix build with ocaml 4.06.

--- fpcache.ml~	2010-10-08 15:44:59.000000000 +0000
+++ fpcache.ml
@@ -50,11 +50,12 @@ let state = ref None
 
 let decompress st i path =
   let l = String.length path in
-  let s = String.create (l + i) in
+  let s = Bytes.create (l + i) in
   String.blit !st 0 s 0 i;
   String.blit path 0 s i l;
-  st := s;
-  s
+  let s' = Bytes.to_string s in
+  st := s';
+  s'
 
 let compress state path =
   let s = state.last in
@@ -74,21 +75,21 @@ let read st ic =
   let fp1 = Digest.input ic in
   let fp2 = Digest.input ic in
   let headerSize = Marshal.header_size in
-  let header = String.create headerSize in
+  let header = Bytes.create headerSize in
   really_input ic header 0 headerSize;
-  if fp1 <> Digest.string header then begin
+  if fp1 <> Digest.string (Bytes.to_string header) then begin
     debug (fun () -> Util.msg "bad header checksum\n");
     raise End_of_file
   end;
   let dataSize = Marshal.data_size header 0 in
-  let s = String.create (headerSize + dataSize) in
-  String.blit header 0 s 0 headerSize;
+  let s = Bytes.create (headerSize + dataSize) in
+  Bytes.blit header 0 s 0 headerSize;
   really_input ic s headerSize dataSize;
-  if fp2 <> Digest.string s then begin
+  if fp2 <> Digest.string (Bytes.to_string s) then begin
     debug (fun () -> Util.msg "bad chunk checksum\n");
     raise End_of_file
   end;
-  let q : entry list = Marshal.from_string s 0 in
+  let q : entry list = Marshal.from_string (Bytes.to_string s) 0 in
   debug (fun () -> Util.msg "read chunk of %d files\n" (List.length q));
   List.iter (fun (l, p, i) -> PathTbl.add tbl (decompress st l p) i) q
 
