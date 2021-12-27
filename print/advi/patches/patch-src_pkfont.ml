$NetBSD: patch-src_pkfont.ml,v 1.1 2021/12/27 00:49:02 dholland Exp $

Hack up the code for immutable strings.

--- src/pkfont.ml~	2007-01-18 14:14:36.000000000 +0000
+++ src/pkfont.ml
@@ -237,7 +237,7 @@ let unpack cdef =
       and h = cdef.height in
       let size = w * h in
       let datalen = (size + 7) lsr 3 in
-      let data = String.make datalen '\000'
+      let data = Bytes.make datalen '\000'
       (* Index into the bitmap *)
       and i = ref 0 and imask = ref 0x80
       (* Index into the bitmap, [w] bits before *)
@@ -246,7 +246,7 @@ let unpack cdef =
       (* Sending a bit to the bitmap *)
       let send_bit b =
 	if b then
-	  data.[!i] <- Char.chr (Char.code data.[!i] lor !imask) ;
+	  Bytes.set data !i (Char.chr (Char.code (Bytes.get data !i) lor !imask)) ;
 	imask := !imask lsr 1 ;
 	if !imask = 0 then begin imask := 0x80 ; incr i end ;
 	jmask := !jmask lsr 1 ;
@@ -254,8 +254,8 @@ let unpack cdef =
       (* Resending n times the last line to the bitmap *)
       let resend_last_line n =
 	for p = 1 to n * w do
-	  if Char.code data.[!j] land !jmask <> 0 then
-	    data.[!i] <- Char.chr (Char.code data.[!i] lor !imask) ;
+	  if Char.code (Bytes.get data !j) land !jmask <> 0 then
+	    Bytes.set data !i (Char.chr (Char.code (Bytes.get data !i) lor !imask)) ;
 	  imask := !imask lsr 1 ;
 	  if !imask = 0 then begin imask := 0x80 ; incr i end ;
 	  jmask := !jmask lsr 1 ;
@@ -295,4 +295,4 @@ let unpack cdef =
 	  black := not !black
 	end
       done ;
-      cdef.bitmap <- Unpacked data ;;
+      cdef.bitmap <- Unpacked (Bytes.to_string data) ;;
