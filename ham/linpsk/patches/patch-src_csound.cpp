$NetBSD: patch-src_csound.cpp,v 1.1 2013/03/02 18:06:22 joerg Exp $

--- src/csound.cpp.orig	2013-02-28 22:13:24.000000000 +0000
+++ src/csound.cpp
@@ -81,7 +81,7 @@ return 0; 
   
 }
                                                           
-CSound::CSound(int ptt = -1):Input(ptt)
+CSound::CSound(int ptt):Input(ptt)
 {
 stream=0;
 audio_buffer.maxbuf=3*BUF_SIZE; // We take 3 buffers
