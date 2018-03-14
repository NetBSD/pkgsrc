$NetBSD: patch-src_utils_cdk_filename2.ml,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/cdk/filename2.ml~	2012-06-24 07:59:41.000000000 +0000
+++ src/utils/cdk/filename2.ml
@@ -116,11 +116,11 @@ let to_string filename =
   List.fold_left (fun file f -> f file) filename !to_strings
 
 let path_of_filename filename =
-  let filename = String.copy filename in
+  let change c =
+     if c = '\\' then '/' else c
+  in
+  let filename = String.map change filename in
   let len = String.length filename in
-  for i = 0 to len - 1 do
-    if filename.[i] = '\\' then filename.[i] <- '/';
-  done;
   let filename = 
     if len > 2 && filename.[1]  = ':' &&
       match filename.[0] with 
@@ -142,11 +142,11 @@ let filesystem_compliant name fs namemax
   (* replace all illegal characters with a valid one.
      assumes all filesystems accept '_'s in filenames *)
   let escape_chars p filename =
-    let s = String.copy filename in
-    for i = 0 to String.length filename - 1 do
-      if p s.[i] then s.[i] <- '_'
-    done;
-    s in
+    let change c =
+       if p c then '_' else c
+    in
+    String.map change filename
+  in
 
   (* remove all illegal characters at the beginning of filename *)
   let trim_left p filename =
