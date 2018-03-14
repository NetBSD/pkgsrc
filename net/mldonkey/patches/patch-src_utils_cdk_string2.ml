$NetBSD: patch-src_utils_cdk_string2.ml,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/cdk/string2.ml~	2007-01-28 20:39:59.000000000 +0000
+++ src/utils/cdk/string2.ml
@@ -163,11 +163,10 @@ let check_suffix s suffix =
   len >= slen && String.sub s (len - slen) slen = suffix
   
 let upp_initial s =
-  if String.length s > 0 then
-    let s = String.copy s in
-    s.[0] <- Char.uppercase s.[0]; s
-  else
-    s
+  let change i c =
+     if i = 0 then Char.uppercase_ascii c else c 
+  in
+  String.mapi change s
     
 (* not optimal !*)
 let rec subequal s1 pos1 s2 pos2 len =
@@ -195,7 +194,7 @@ let subcontains s sub =
   
 let of_char c = String.make 1 c
   
-  
+(* problematic with immutable strings
 let resize s newlen =
   let len = String.length s in
   if len > newlen then String.sub s 0 newlen 
@@ -203,13 +202,10 @@ let resize s newlen =
   let str = String.create newlen in
   String.blit s 0 str 0 len;
   str
+*)
   
 let init len f =
-  let s = String.create len in
-  for i = 0 to len - 1 do
-    s.[i] <- f i
-  done;
-  s
+  String.init len f
 
 let is_space c = c = ' ' || c = '\n' || c = '\r' || c = '\t'
   
@@ -266,30 +262,24 @@ let starts_with s1 s2 =
   let len2 = String.length s2 in
   len2 <= len1 && strneql s1 s2 len2
 
-let replace_char s c1 c2 =
-  for i = 0 to String.length s - 1 do
-    if s.[i] == c1 then s.[i] <- c2
-  done
+let replace_char' s c1 c2 =
+  let change i c =
+    if c = c1 then c2 else c
+  in
+  String.mapi change s
 
 let stem s =
-  let s = String.lowercase (String.copy s) in
-  for i = 0 to String.length s - 1 do
-    let c = s.[i] in
+  let munge i c =
     match c with
-      'a'..'z' | '0' .. '9' -> ()
-    | _ -> s.[i] <- ' ';
-  done;
+      'a'..'z' | '0' .. '9' -> c
+    | _ -> ' '
+  in
+  let s = String.mapi munge (String.lowercase_ascii s) in
   split_simplify s ' '
   
 let map f s =
   let len = String.length s in
-  if len = 0 then [||] else
-  let v = f s.[0] in
-  let array = Array.create len v in
-  for i = 1 to len -1 do 
-    array.(i) <- f s.[i]
-  done;
-  array
+  Array.init len (fun i -> f s.[i])
   
 let iteri f s =
   let len = String.length s in
@@ -298,11 +288,7 @@ let iteri f s =
   done
   
 let init n f =
-  let s = String.create n in
-  for i = 0 to n - 1 do
-    s.[i] <- f i 
-  done;
-  s
+  String.init n f
 
 let exists p s =
   let l = String.length s in
