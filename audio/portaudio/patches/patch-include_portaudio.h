$NetBSD: patch-include_portaudio.h,v 1.1 2019/10/26 17:22:39 nia Exp $

Add features needed to make portmixer work in audacity.

--- include/portaudio.h.orig	2016-10-30 01:23:04.000000000 +0000
+++ include/portaudio.h
@@ -1197,6 +1197,15 @@ signed long Pa_GetStreamReadAvailable( P
 signed long Pa_GetStreamWriteAvailable( PaStream* stream );
 
 
+/** Retrieve the host type handling an open stream.
+
+ @return Returns a non-negative value representing the host API type
+ handling an open stream or, a PaErrorCode (which are always negative)
+ if PortAudio is not initialized or an error is encountered.
+*/
+PaHostApiTypeId Pa_GetStreamHostApiType( PaStream* stream );
+
+
 /* Miscellaneous utilities */
 
 
