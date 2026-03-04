$NetBSD: patch-music2_wavfile.cc,v 1.2 2026/03/04 12:38:01 tsutsui Exp $

- appease -Wwrite-strings warnings
- fix incorrect frequency of the input wav file
- fix an undefined behavior
- fix incorrect parentheses

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
 
@@ -217,7 +217,7 @@ static char* WavGetInfo(WAVFILE* wfile, 
 
 	if ( (e = WaveHeaderCheck(data,
 				  &channels,&samplerate,
-				  &sample_bits,&samples,&datastart) != 0 )) {
+				  &sample_bits,&samples,&datastart)) != 0 ) {
 		fprintf(stderr,"WavGetInfo(): Reading WAV header\n");
 		return 0;
 	}
@@ -303,7 +303,7 @@ WAVFILE_Stream::WAVFILE_Stream(FILE* _st
 	return;
 }
 WAVFILE_Stream::~WAVFILE_Stream() {
-	if (data_orig) delete data_orig;
+	if (data_orig) delete[] data_orig;
 	if (stream) fclose(stream);
 	return;
 }
@@ -328,8 +328,8 @@ WAVFILE* WAVFILE::MakeConverter(WAVFILE*
 	if (new_reader->wavinfo.DataBits == 8) from_format = AUDIO_S8;
 	else from_format = AUDIO_S16;
 	SDL_AudioCVT* cvt = new SDL_AudioCVT;
-	int ret = SDL_BuildAudioCVT(cvt, from_format, new_reader->wavinfo.Channels, freq,
-		format, 2, freq);
+	int ret = SDL_BuildAudioCVT(cvt, from_format, new_reader->wavinfo.Channels, new_reader->wavinfo.SamplingRate,
+		format, channels, freq);
 	if (ret == -1) {
 		delete cvt;
 		fprintf(stderr,"Cannot make wave file converter!!!\n");
