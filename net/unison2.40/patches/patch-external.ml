$NetBSD: patch-external.ml,v 1.1 2018/03/14 11:16:15 dholland Exp $

Fix build with ocaml 4.06.

--- external.ml~	2010-04-15 17:29:31.000000000 +0000
+++ external.ml
@@ -44,7 +44,7 @@ let readChannelTillEof_lwt c =
       Some l -> loop (l :: lines)
     | None   -> lines
   in
-  String.concat "\n" (Safelist.rev (loop []))
+  Bytes.concat (Bytes.of_string "\n") (Safelist.rev (loop []))
 
 let readChannelsTillEof l =
   let rec suckitdry lines c =
@@ -58,7 +58,7 @@ let readChannelsTillEof l =
   Lwt_util.map
     (fun c ->
        suckitdry [] c
-       >>= (fun res -> return (String.concat "\n" (Safelist.rev res))))
+       >>= (fun res -> return (Bytes.concat (Bytes.of_string "\n") (Safelist.rev res))))
     l
 
 let runExternalProgram cmd =
@@ -82,8 +82,8 @@ let runExternalProgram cmd =
     readChannelsTillEof [out;err]
     >>= (function [logOut;logErr] ->
     let returnValue = System.close_process_full desc in
-    let logOut = Util.trimWhitespace logOut in
-    let logErr = Util.trimWhitespace logErr in
+    let logOut = Util.trimWhitespace (Bytes.to_string logOut) in
+    let logErr = Util.trimWhitespace (Bytes.to_string logErr) in
     return (returnValue, (
       (*  cmd
       ^ "\n\n" ^ *)
