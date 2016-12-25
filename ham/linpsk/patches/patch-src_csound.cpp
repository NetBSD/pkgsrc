$NetBSD: patch-src_csound.cpp,v 1.2 2016/12/25 21:45:09 joerg Exp $

--- src/csound.cpp.orig	2005-02-20 10:05:46.000000000 +0000
+++ src/csound.cpp
@@ -81,7 +81,7 @@ return 0; 
   
 }
                                                           
-CSound::CSound(int ptt = -1):Input(ptt)
+CSound::CSound(int ptt):Input(ptt)
 {
 stream=0;
 audio_buffer.maxbuf=3*BUF_SIZE; // We take 3 buffers
@@ -92,7 +92,7 @@ output=false;
 }
 CSound::~CSound()
 {
-if ( audio_buffer.audiobuffer >0)
+if ( audio_buffer.audiobuffer )
 	delete audio_buffer.audiobuffer;
 }
 
