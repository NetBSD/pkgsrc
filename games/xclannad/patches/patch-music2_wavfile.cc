$NetBSD: patch-music2_wavfile.cc,v 1.1 2026/03/04 10:27:19 tsutsui Exp $

- appease -Wwrite-strings warnings

--- music2/wavfile.cc.orig	2008-08-31 09:52:12.000000000 +0000
+++ music2/wavfile.cc
@@ -105,7 +105,7 @@ typedef  struct
 
 
 static void waveFormatCopy( WAVEFORMAT* wav, char *ptr );
-static char*  findchunk (char* s1, char* s2, size_t n) ;
+static char*  findchunk (char* s1, const char* s2, size_t n) ;
 
 static int  WaveHeaderCheck  (char *wave_buf,int* channels, u_long* samplerate, int* samplebits, u_long* samples,u_long* datastart)
 {	
@@ -176,7 +176,7 @@ static int  WaveHeaderCheck  (char *wave
 } ; /* WaveHeaderCheck*/
 
 
-static char* findchunk  (char* pstart, char* fourcc, size_t n)
+static char* findchunk  (char* pstart, const char* fourcc, size_t n)
 {	char	*pend ;
 	int		k, test ;
 
