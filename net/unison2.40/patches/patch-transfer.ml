$NetBSD: patch-transfer.ml,v 1.1 2018/03/14 11:16:15 dholland Exp $

Fix build with ocaml 4.06.

--- transfer.ml.orig	2010-04-15 17:29:31.000000000 +0000
+++ transfer.ml
@@ -240,13 +240,13 @@ let send infd length showProgress transm
   let timer = Trace.startTimer "Sending file using generic transmission" in
   let bufSz = 8192 in
   let bufSzFS = Uutil.Filesize.ofInt 8192 in
-  let buf = String.create bufSz in
+  let buf = Bytes.create bufSz in
   let q = makeQueue 0 in
   let rec sendSlice length =
     let count =
       reallyRead infd buf 0
         (if length > bufSzFS then bufSz else Uutil.Filesize.toInt length) in
-    queueToken q showProgress transmit (STRING (buf, 0, count)) >>= (fun () ->
+    queueToken q showProgress transmit (STRING (Bytes.to_string buf, 0, count)) >>= (fun () ->
     let length = Uutil.Filesize.sub length (Uutil.Filesize.ofInt count) in
     if count = bufSz && length > Uutil.Filesize.zero then
       sendSlice length
@@ -266,7 +266,7 @@ let rec receiveRec outfd showProgress da
       let length = decodeInt2 data (pos + 1) in
       if Trace.enabled "generic" then debug (fun() -> Util.msg
           "receiving %d bytes\n" length);
-      reallyWrite outfd (Bytearray.sub data (pos + 3) length) 0 length;
+      reallyWrite outfd (Bytes.of_string (Bytearray.sub data (pos + 3) length)) 0 length;
       showProgress length;
       receiveRec outfd showProgress data (pos + length + 3) maxPos
   | 'E' ->
@@ -347,7 +347,7 @@ struct
      and eventually handles the buffer update. *)
   let blockIter infd f blockSize maxCount =
     let bufferSize = 8192 + blockSize in
-    let buffer = String.create bufferSize in
+    let buffer = Bytes.create bufferSize in
     let rec iter count offset length =
       if count = maxCount then
         count
@@ -358,7 +358,7 @@ struct
           iter (count + 1) newOffset length
         end else if offset > 0 then begin
           let chunkSize = length - offset in
-          String.blit buffer offset buffer 0 chunkSize;
+          Bytes.blit buffer offset buffer 0 chunkSize;
           iter count 0 chunkSize
         end else begin
           let l = input infd buffer length (bufferSize - length) in
@@ -384,6 +384,7 @@ struct
       Bigarray.Array1.create Bigarray.int32 Bigarray.c_layout blockCount in
     let strongCs = Bytearray.create (blockCount * csSize) in
     let addBlock i buf offset =
+      let buf = Bytes.to_string buf in
       weakCs.{i} <- Int32.of_int (Checksum.substring buf offset blockSize);
       Bytearray.blit_from_string
         (Digest.substring buf offset blockSize) 0 strongCs (i * csSize) csSize
@@ -414,7 +415,7 @@ struct
   (* For each transfer instruction, either output a string or copy one or
      several blocks from the old file. *)
   let rsyncDecompress blockSize infd outfd showProgress (data, pos, len) =
-    let decomprBuf = String.create decomprBufSize in
+    let decomprBuf = Bytes.create decomprBufSize in
     let progress = ref 0 in
     let rec copy length =
       if length > decomprBufSize then begin
@@ -440,7 +441,7 @@ struct
           if Trace.enabled "rsynctoken" then
             debugToken (fun() ->
               Util.msg "decompressing string (%d bytes)\n" length);
-          reallyWrite outfd (Bytearray.sub data (pos + 3) length) 0 length;
+          reallyWrite outfd (Bytes.of_string (Bytearray.sub data (pos + 3) length)) 0 length;
           progress := !progress + length;
           decode (pos + length + 3)
       | 'B' ->
@@ -499,16 +500,16 @@ struct
 
   let sigFilter hashTableLength signatures =
     let len = hashTableLength lsl 2 in
-    let filter = String.make len '\000' in
+    let filter = Bytes.make len '\000' in
     for k = 0 to signatures.blockCount - 1 do
       let cs = Int32.to_int signatures.weakChecksum.{k} land 0x7fffffff in
       let h1 = cs lsr 28 in
       assert (h1 >= 0 && h1 < 8);
       let h2 = (cs lsr 5) land (len - 1) in
       let mask = 1 lsl h1 in
-      filter.[h2] <- Char.chr (Char.code filter.[h2] lor mask)
+      Bytes.set filter h2 (Char.chr (Char.code (Bytes.get filter h2) lor mask))
     done;
-    filter
+    Bytes.to_string filter
 
   let filterMem filter hashTableLength checksum =
     let len = hashTableLength lsl 2 in
@@ -647,12 +648,12 @@ struct
     in
 
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
@@ -676,7 +677,7 @@ struct
         let chunkSize = st.length - st.offset in
         if chunkSize > 0 then begin
           assert(comprBufSize >= blockSize);
-          String.blit comprBuf st.offset comprBuf 0 chunkSize
+          Bytes.blit comprBuf st.offset comprBuf 0 chunkSize
         end;
         let rem = Uutil.Filesize.sub srcLength st.absolutePos in
         let avail = comprBufSize - chunkSize in
@@ -703,19 +704,19 @@ struct
       if miss then
         rollChecksum st
       else begin
-        let cksum = Checksum.substring comprBuf st.offset blockSize in
+        let cksum = Checksum.substring (Bytes.to_string comprBuf) st.offset blockSize in
         st.checksum <- cksum;
-        st.cksumOutgoing <- String.unsafe_get comprBuf st.offset;
+        st.cksumOutgoing <- Bytes.unsafe_get comprBuf st.offset;
         processBlock st
       end
 
     and rollChecksum st =
       let ingoingChar =
-        String.unsafe_get comprBuf (st.offset + blockSize - 1) in
+        Bytes.unsafe_get comprBuf (st.offset + blockSize - 1) in
       let cksum =
         Checksum.roll cksumTable st.checksum st.cksumOutgoing ingoingChar in
       st.checksum <- cksum;
-      st.cksumOutgoing <- String.unsafe_get comprBuf st.offset;
+      st.cksumOutgoing <- Bytes.unsafe_get comprBuf st.offset;
       if filterMem filter hashTableLength cksum then
         processBlock st
       else
@@ -746,7 +747,7 @@ struct
           -1
       | (k, cs) :: tl, None
         when cs = checksum ->
-          let fingerprint = Digest.substring comprBuf st.offset blockSize in
+          let fingerprint = Digest.substring (Bytes.to_string comprBuf) st.offset blockSize in
           findBlock st checksum entry (Some fingerprint)
       | (k, cs) :: tl, Some fingerprint
         when cs = checksum && fingerprintMatch k fingerprint ->
