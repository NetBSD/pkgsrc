$NetBSD: patch-transfer.ml,v 1.1 2018/03/14 10:16:03 dholland Exp $

Fix build with ocaml 4.06.

--- transfer.ml~	2009-06-18 08:36:04.000000000 +0000
+++ transfer.ml
@@ -251,13 +251,13 @@ let send infd length showProgress transm
   let timer = Trace.startTimer "Sending file using generic transmission" in
   let bufSz = 8192 in
   let bufSzFS = Uutil.Filesize.ofInt 8192 in
-  let buf = String.create bufSz in
+  let buf = Bytes.create bufSz in
   let q = makeQueue length in
   let rec sendSlice length =
     let count =
       reallyRead infd buf 0
         (if length > bufSzFS then bufSz else Uutil.Filesize.toInt length) in
-    queueToken q showProgress transmit (STRING (buf, 0, count)) >>= (fun () ->
+    queueToken q showProgress transmit (STRING (Bytes.to_string buf, 0, count)) >>= (fun () ->
     let length = Uutil.Filesize.sub length (Uutil.Filesize.ofInt count) in
     if count = bufSz && length > Uutil.Filesize.zero then
       sendSlice length
@@ -277,7 +277,7 @@ let rec receiveRec outfd showProgress da
       let length = decodeInt2 data (pos + 1) in
       if Trace.enabled "generic" then debug (fun() -> Util.msg
           "receiving %d bytes\n" length);
-      reallyWrite outfd (Bytearray.sub data (pos + 3) length) 0 length;
+      reallyWrite outfd (Bytes.of_string (Bytearray.sub data (pos + 3) length)) 0 length;
       showProgress length;
       receiveRec outfd showProgress data (pos + length + 3) maxPos
   | 'E' ->
@@ -321,7 +321,7 @@ struct
      and eventually handles the buffer update. *)
   let blockIter infd f arg maxCount =
     let bufferSize = 8192 + blockSize in
-    let buffer = String.create bufferSize in
+    let buffer = Bytes.create bufferSize in
     let rec iter count arg offset length =
       if count = maxCount then arg else begin
         let newOffset = offset + blockSize in
@@ -329,7 +329,7 @@ struct
           iter (count + 1) (f buffer offset arg) newOffset length
         else if offset > 0 then begin
           let chunkSize = length - offset in
-          String.blit buffer offset buffer 0 chunkSize;
+          Bytes.blit buffer offset buffer 0 chunkSize;
           iter count arg 0 chunkSize
         end else begin
           let l = input infd buffer length (bufferSize - length) in
@@ -359,6 +359,7 @@ struct
     debugLog (fun() -> Util.msg "block size = %d bytes\n" blockSize);
     let timer = Trace.startTimer "Preprocessing old file" in
     let addBlock buf offset rev_bi =
+      let buf = Bytes.to_string buf in
       let cs = Checksum.substring buf offset blockSize in
       let fp =   Digest.substring buf offset blockSize in
       (cs, fp) :: rev_bi
@@ -383,7 +384,7 @@ struct
   (* For each transfer instruction, either output a string or copy one or
      several blocks from the old file. *)
   let rsyncDecompress infd outfd showProgress (data, pos, len) =
-    let decomprBuf = String.create decomprBufSize in
+    let decomprBuf = Bytes.create decomprBufSize in
     let progress = ref 0 in
     let rec copy length =
       if length > decomprBufSize then begin
@@ -409,7 +410,7 @@ struct
           if Trace.enabled "rsynctoken" then
             debugToken (fun() ->
               Util.msg "decompressing string (%d bytes)\n" length);
-          reallyWrite outfd (Bytearray.sub data (pos + 3) length) 0 length;
+          reallyWrite outfd (Bytes.of_string (Bytearray.sub data (pos + 3) length)) 0 length;
           progress := !progress + length;
           decode (pos + length + 3)
       | 'B' ->
@@ -584,12 +585,12 @@ struct
     logHash blockTable !hashTableLength;
 
     (* Create the compression buffer *)
-    let comprBuf = String.create comprBufSize in
+    let comprBuf = Bytes.create comprBufSize in
 
     (* If there is data waiting to be sent, transmit it as a STRING token *)
     let transmitString toBeSent offset =
       if offset > toBeSent then
-        transmit (STRING (comprBuf, toBeSent, offset - toBeSent))
+        transmit (STRING (Bytes.to_string comprBuf, toBeSent, offset - toBeSent))
       else
         return ()
     in
@@ -611,7 +612,7 @@ struct
         let chunkSize = length - newOffset in
         if chunkSize > 0 then begin
           assert(comprBufSize >= blockSize);
-          String.blit comprBuf newOffset comprBuf 0 chunkSize
+          Bytes.blit comprBuf newOffset comprBuf 0 chunkSize
         end;
         let rem = Uutil.Filesize.sub srcLength !absolutePos in
         let avail = comprBufSize - chunkSize in
@@ -636,12 +637,12 @@ struct
       let cksum =
         if miss then
           Checksum.roll !cksumTable !checksum !cksumOutgoing
-            (String.unsafe_get comprBuf (newOffset + blockSize - 1))
+            (Bytes.unsafe_get comprBuf (newOffset + blockSize - 1))
         else
-          Checksum.substring comprBuf newOffset blockSize
+          Checksum.substring (Bytes.to_string comprBuf) newOffset blockSize
       in
       checksum := cksum;
-      cksumOutgoing := String.unsafe_get comprBuf newOffset;
+      cksumOutgoing := Bytes.unsafe_get comprBuf newOffset;
       processBlock newOffset toBeSent length cksum
 
     (* Try to match the current block with one existing in the old file *)
@@ -672,7 +673,7 @@ struct
           -1
       | (k, cs, fp) :: tl, None
         when cs = checksum ->
-          let fingerprint = Digest.substring comprBuf offset blockSize in
+          let fingerprint = Digest.substring (Bytes.to_string comprBuf) offset blockSize in
           findBlock offset checksum entry (Some fingerprint)
       | (k, cs, fp) :: tl, Some fingerprint
         when (cs = checksum) && (fp = fingerprint) ->
