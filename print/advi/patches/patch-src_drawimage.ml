$NetBSD: patch-src_drawimage.ml,v 1.1 2021/12/27 00:49:02 dholland Exp $

Hack up the code for immutable strings.

--- src/drawimage.ml~	2007-01-18 14:14:35.000000000 +0000
+++ src/drawimage.ml
@@ -161,10 +161,20 @@ let after f g = try let x = f () in  g (
 
 let cache_path file whitetransp psbbox ratiopt antialias (w, h) =
   let file' = Userfile.fullpath (Unix.getcwd ()) file in
+(*
   let file' = if file == file' then String.copy file' else file' in
   for i = 0 to String.length file' - 1 do
     if file'.[i] = '/' then file'.[i] <- '-'
   done;
+*)
+  let file' =
+     let f i =
+        match String.get file' i with
+        | '/' -> '-'
+        | c -> c
+     in
+     String.init (String.length file') f
+  in
   let geom_string x =
     if x >= 0 then "+" ^ string_of_int x else string_of_int x
   in
@@ -206,9 +216,9 @@ let cache_path file whitetransp psbbox r
 let cache_load file =
   debugs ("cache_load " ^ file);
   let load ic =
-    let s = String.create (String.length cache_key) in
+    let s = Bytes.create (String.length cache_key) in
     ignore (input ic s 0 (String.length cache_key));
-    if s <> cache_key then failwith (file ^ " has no proper header");
+    if Bytes.to_string s <> cache_key then failwith (file ^ " has no proper header");
     let rgba = input_value ic in (* bool *)
     let width = input_value ic in
     let height = input_value ic in
@@ -237,7 +247,7 @@ let cache_load file =
 let cache_save file img =
   debugs ("cache_save " ^ file);
   let save oc =
-    output oc cache_key 0 (String.length cache_key);
+    output oc (Bytes.of_string cache_key) 0 (String.length cache_key);
     match img with
     | Rgba32 image ->
         output_value oc true;
