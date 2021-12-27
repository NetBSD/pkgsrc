$NetBSD: patch-src_grdev.ml,v 1.1 2021/12/27 00:49:02 dholland Exp $

Hack up the code for immutable strings.

--- src/grdev.ml~	2011-08-05 08:24:17.000000000 +0000
+++ src/grdev.ml
@@ -169,12 +169,12 @@ let inputp fdins = 
   | _, _, _ -> true
 
 let get_input () =
-  let buf = String.create 1 in
+  let buf = Bytes.create 1 in
   if inputp [ Unix.stdin ] then
     let _ = Unix.read Unix.stdin buf 0 1 in 
     if inputp [ Unix.stdin ] then () 
     else clear_usr2();
-    buf.[0]
+    Bytes.get buf 0
   else assert false;;
 
 let watch_file_check () = 
