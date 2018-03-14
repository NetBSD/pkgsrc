$NetBSD: patch-remote.ml,v 1.1 2018/03/14 10:16:03 dholland Exp $

Fix build with ocaml 4.06.

--- remote.ml~	2009-05-29 14:00:18.000000000 +0000
+++ remote.ml
@@ -79,10 +79,10 @@ let catch_io_errors th =
 
 type connection =
   { inputChannel : Unix.file_descr;
-    inputBuffer : string;
+    inputBuffer : bytes;
     mutable inputLength : int;
     outputChannel : Unix.file_descr;
-    outputBuffer : string;
+    outputBuffer : bytes;
     mutable outputLength : int;
     outputQueue : (Bytearray.t * int * int) list Queue.t;
     mutable pendingOutput : bool;
@@ -107,7 +107,7 @@ let fill_inputBuffer conn =
            Util.msg "grab: EOF\n"
          else
            Util.msg "grab: %s\n"
-             (String.escaped (String.sub conn.inputBuffer 0 len)));
+             (String.escaped (Bytes.to_string (Bytes.sub conn.inputBuffer 0 len))));
        if len = 0 then
          lost_connection ()
        else begin
@@ -122,10 +122,10 @@ let rec grab_rec conn s pos len =
     grab_rec conn s pos len)
   end else begin
     let l = min (len - pos) conn.inputLength in
-    Bytearray.blit_from_string conn.inputBuffer 0 s pos l;
+    Bytearray.blit_from_bytes conn.inputBuffer 0 s pos l;
     conn.inputLength <- conn.inputLength - l;
     if conn.inputLength > 0 then
-      String.blit conn.inputBuffer l conn.inputBuffer 0 conn.inputLength;
+      Bytes.blit conn.inputBuffer l conn.inputBuffer 0 conn.inputLength;
     if pos + l < len then
       grab_rec conn s (pos + l) len
     else
@@ -138,7 +138,7 @@ let grab conn s len =
   grab_rec conn s 0 len
 
 let peek_without_blocking conn =
-  String.sub conn.inputBuffer 0 conn.inputLength
+  Bytes.to_string (Bytes.sub conn.inputBuffer 0 conn.inputLength)
 
 (****)
 
@@ -152,11 +152,11 @@ let rec send_output conn =
          >>= (fun len ->
        debugV (fun() ->
          Util.msg "dump: %s\n"
-           (String.escaped (String.sub conn.outputBuffer 0 len)));
+           (String.escaped (Bytes.to_string (Bytes.sub conn.outputBuffer 0 len))));
        emittedBytes := !emittedBytes +. float len;
        conn.outputLength <- conn.outputLength - len;
        if conn.outputLength > 0 then
-         String.blit
+         Bytes.blit
            conn.outputBuffer len conn.outputBuffer 0 conn.outputLength;
        Lwt.return ()))
 
@@ -166,7 +166,7 @@ let rec fill_buffer_2 conn s pos len =
     fill_buffer_2 conn s pos len)
   else begin
     let l = min (len - pos) (outputBuffer_size - conn.outputLength) in
-    Bytearray.blit_to_string s pos conn.outputBuffer conn.outputLength l;
+    Bytearray.blit_to_bytes s pos conn.outputBuffer conn.outputLength l;
     conn.outputLength <- conn.outputLength + l;
     if pos + l < len then
       fill_buffer_2 conn s (pos + l) len
@@ -302,10 +302,10 @@ let setupIO in_ch out_ch =
     Unix.set_nonblock out_ch
   end;
   { inputChannel = in_ch;
-    inputBuffer = String.create inputBuffer_size;
+    inputBuffer = Bytes.create inputBuffer_size;
     inputLength = 0;
     outputChannel = out_ch;
-    outputBuffer = String.create outputBuffer_size;
+    outputBuffer = Bytes.create outputBuffer_size;
     outputLength = 0;
     outputQueue = Queue.create ();
     pendingOutput = false;
@@ -1078,7 +1078,7 @@ let openConnectionReply = function
     (i1,i2,o1,o2,s,Some fdTerm,clroot,pid) ->
     (fun response ->
       (* FIX: should loop on write, watch for EINTR, etc. *)
-      ignore(Unix.write fdTerm (response ^ "\n") 0 (String.length response + 1)))
+      ignore(Unix.write fdTerm (Bytes.of_string (response ^ "\n")) 0 (String.length response + 1)))
   | _ -> (fun _ -> ())
 
 let openConnectionEnd (i1,i2,o1,o2,s,_,clroot,pid) =
