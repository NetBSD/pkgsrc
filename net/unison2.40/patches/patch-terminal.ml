$NetBSD: patch-terminal.ml,v 1.1 2018/03/14 11:16:15 dholland Exp $

Fix build with ocaml 4.06.

--- terminal.ml.orig	2010-10-11 13:29:09.000000000 +0000
+++ terminal.ml
@@ -222,14 +222,14 @@ let (>>=) = Lwt.bind
 (* Wait until there is input. If there is terminal input s,
    return Some s. Otherwise, return None. *)
 let rec termInput fdTerm fdInput =
-  let buf = String.create 10000 in
+  let buf = Bytes.create 10000 in
   let rec readPrompt () =
     Lwt_unix.read fdTerm buf 0 10000 >>= fun len ->
     if len = 0 then
       (* The remote end is dead *)
       Lwt.return None
     else
-      let query = String.sub buf 0 len in
+      let query = Bytes.to_string (Bytes.sub buf 0 len) in
       if query = "\r\n" then
         readPrompt ()
       else
@@ -244,20 +244,20 @@ let rec termInput fdTerm fdInput =
 
 (* Read messages from the terminal and use the callback to get an answer *)
 let handlePasswordRequests fdTerm callback =
-  let buf = String.create 10000 in
+  let buf = Bytes.create 10000 in
   let rec loop () =
     Lwt_unix.read fdTerm buf 0 10000 >>= (fun len ->
       if len = 0 then
         (* The remote end is dead *)
         Lwt.return ()
       else
-        let query = String.sub buf 0 len in
-        if query = "\r\n" then
+        let query = Bytes.sub buf 0 len in
+        if Bytes.to_string query = "\r\n" then
           loop ()
         else begin
-          let response = callback query in
+          let response = callback (Bytes.to_string query) in
           Lwt_unix.write fdTerm
-            (response ^ "\n") 0 (String.length response + 1)
+            (Bytes.of_string (response ^ "\n")) 0 (String.length response + 1)
               >>= (fun _ ->
           loop ())
         end)
