$NetBSD: patch-terminal.ml,v 1.1 2018/03/14 10:16:03 dholland Exp $

Fix build with ocaml 4.06.

--- terminal.ml~	2009-05-02 02:31:27.000000000 +0000
+++ terminal.ml
@@ -208,14 +208,14 @@ let rec termInput fdTerm fdInput =
   (* read a line of input *)
   let msg =
     let n = 1024 in (* Assume length of input from terminal < n *)
-    let s = String.create n in
+    let s = Bytes.create n in
     let howmany =
       let rec loop() =
         try Unix.read fdTerm s 0 n
         with Unix.Unix_error(Unix.EINTR,_,_) -> loop() in
       loop() in
     if howmany <= 0 then "" else
-    String.sub s 0 howmany in
+    Bytes.to_string (Bytes.sub s 0 howmany) in
   let len = String.length msg in
   if len = 0 then None (* the terminal has been closed *)
   else if len = 2 && msg.[0] = '\r' && msg.[1] = '\n' then
@@ -227,20 +227,20 @@ let (>>=) = Lwt.bind
 (* Read messages from the terminal and use the callback to get an answer *)
 let handlePasswordRequests fdTerm callback =
   Unix.set_nonblock fdTerm;
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
