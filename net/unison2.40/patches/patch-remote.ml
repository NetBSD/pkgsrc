$NetBSD: patch-remote.ml,v 1.1 2018/03/14 11:16:15 dholland Exp $

Fix build with ocaml 4.06.

--- remote.ml~	2010-04-15 17:29:31.000000000 +0000
+++ remote.ml
@@ -116,7 +116,7 @@ let emittedBytes = ref 0.
 
 type ioBuffer =
   { channel : Lwt_unix.file_descr;
-    buffer : string;
+    buffer : bytes;
     mutable length : int;
     mutable opened : bool }
 
@@ -125,7 +125,7 @@ let bufferSize = 16384
    buffer of this size *)
 
 let makeBuffer ch =
-  { channel = ch; buffer = String.create bufferSize;
+  { channel = ch; buffer = Bytes.create bufferSize;
     length = 0; opened = true }
 
 (****)
@@ -142,7 +142,7 @@ let fillInputBuffer conn =
            Util.msg "grab: EOF\n"
          else
            Util.msg "grab: %s\n"
-             (String.escaped (String.sub conn.buffer 0 len)));
+             (String.escaped (Bytes.to_string (Bytes.sub conn.buffer 0 len))));
        if len = 0 then
          lostConnection ()
        else begin
@@ -157,10 +157,10 @@ let rec grabRec conn s pos len =
     grabRec conn s pos len
   end else begin
     let l = min (len - pos) conn.length in
-    Bytearray.blit_from_string conn.buffer 0 s pos l;
+    Bytearray.blit_from_bytes conn.buffer 0 s pos l;
     conn.length <- conn.length - l;
     if conn.length > 0 then
-      String.blit conn.buffer l conn.buffer 0 conn.length;
+      Bytes.blit conn.buffer l conn.buffer 0 conn.length;
     if pos + l < len then
       grabRec conn s (pos + l) len
     else
@@ -173,7 +173,7 @@ let grab conn s len =
   grabRec conn s 0 len
 
 let peekWithoutBlocking conn =
-  String.sub conn.buffer 0 conn.length
+  Bytes.to_string (Bytes.sub conn.buffer 0 conn.length)
 
 (****)
 
@@ -189,11 +189,11 @@ let rec sendOutput conn =
        end >>= fun len ->
        debugV (fun() ->
          Util.msg "dump: %s\n"
-           (String.escaped (String.sub conn.buffer 0 len)));
+           (String.escaped (Bytes.to_string (Bytes.sub conn.buffer 0 len))));
        emittedBytes := !emittedBytes +. float len;
        conn.length <- conn.length - len;
        if conn.length > 0 then
-         String.blit
+         Bytes.blit
            conn.buffer len conn.buffer 0 conn.length;
        Lwt.return ())
 
@@ -203,7 +203,7 @@ let rec fillBuffer2 conn s pos len =
     fillBuffer2 conn s pos len
   else begin
     let l = min (len - pos) (bufferSize - conn.length) in
-    Bytearray.blit_to_string s pos conn.buffer conn.length l;
+    Bytearray.blit_to_bytes s pos conn.buffer conn.length l;
     conn.length <- conn.length + l;
     if pos + l < len then
       fillBuffer2 conn s (pos + l) len
@@ -1340,7 +1340,7 @@ let openConnectionReply = function
     (i1,i2,o1,o2,s,Some fdTerm,clroot,pid) ->
     (fun response ->
       (* FIX: should loop until everything is written... *)
-      ignore (Lwt_unix.run (Lwt_unix.write fdTerm (response ^ "\n") 0
+      ignore (Lwt_unix.run (Lwt_unix.write fdTerm (Bytes.of_string (response ^ "\n")) 0
                               (String.length response + 1))))
   | _ -> (fun _ -> ())
 
