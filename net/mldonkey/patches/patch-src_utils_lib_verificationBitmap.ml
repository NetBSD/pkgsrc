$NetBSD: patch-src_utils_lib_verificationBitmap.ml,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/lib/verificationBitmap.ml~	2006-06-11 17:39:51.000000000 +0000
+++ src/utils/lib/verificationBitmap.ml
@@ -1,4 +1,4 @@
-type t = string
+type t = bytes
 type part_state = 
     State_missing | State_partial | State_complete | State_verified
 	
@@ -15,24 +15,24 @@ let char_to_state = function
   | '3' -> State_verified 
   | _ -> assert false
 
-let create n c = String.make n (state_to_char c)
-let get x i = (char_to_state x.[i])
-let set x i c = x.[i] <- state_to_char c
-let length = String.length 
+let create n c = Bytes.make n (state_to_char c)
+let get x i = char_to_state (Bytes.get x i)
+let set x i c = Bytes.set x i (state_to_char c)
+let length = Bytes.length 
 let init n f =
-  let s = String.create n in
+  let s = Bytes.create n in
   for i = 0 to n - 1 do
     set s i (f i)
   done;
   s
-let to_string x = x
-let of_string x = x
+let to_string x = Bytes.to_string x
+let of_string x = Bytes.of_string x
   
 let iteri f x = 
-  let l = String.length x in
+  let l = Bytes.length x in
   let rec aux i =
     if i < l then begin
-      f i (char_to_state x.[i]);
+      f i (char_to_state (Bytes.get x i));
       aux (i+1)
     end in
   aux 0
@@ -41,20 +41,20 @@ let mapi f x =
   Array.init (length x) (fun i -> f i (get x i))
     
 let fold_lefti f acc x =
-  let l = String.length x in
+  let l = Bytes.length x in
   let rec aux acc i =
     if i = l then acc
     else aux (f acc i (get x i)) (i + 1) in
   aux acc 0
     
 let existsi p x = 
-  let l = String.length x in
+  let l = Bytes.length x in
   let rec aux i =
-    i < l && (p i (char_to_state x.[i]) || aux (i+1)) in
+    i < l && (p i (char_to_state (Bytes.get x i)) || aux (i+1)) in
   aux 0
     
 let for_all p s =
-  let l = String.length s in
+  let l = Bytes.length s in
   let rec aux i =
-    i >= l || p (char_to_state s.[i]) && aux (i+1) in
+    i >= l || p (char_to_state (Bytes.get s i)) && aux (i+1) in
   aux 0
