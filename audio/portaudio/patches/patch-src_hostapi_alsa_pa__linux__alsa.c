$NetBSD: patch-src_hostapi_alsa_pa__linux__alsa.c,v 1.3 2020/04/17 15:50:03 nia Exp $

- Support building on non-Linux systems.
- Add features needed to make portmixer work with audacity.

--- src/hostapi/alsa/pa_linux_alsa.c.orig	2016-10-30 01:23:04.000000000 +0000
+++ src/hostapi/alsa/pa_linux_alsa.c
@@ -79,6 +79,10 @@
 
 #include "pa_linux_alsa.h"
 
+#ifndef ESTRPIPE
+    #define ESTRPIPE EPIPE
+#endif
+
 /* Add missing define (for compatibility with older ALSA versions) */
 #ifndef SND_PCM_TSTAMP_ENABLE
     #define SND_PCM_TSTAMP_ENABLE SND_PCM_TSTAMP_MMAP
@@ -621,6 +625,7 @@ typedef struct
     StreamDirection streamDir;
 
     snd_pcm_channel_area_t *channelAreas;  /* Needed for channel adaption */
+    int card;
 } PaAlsaStreamComponent;
 
 /* Implementation specific stream structure */
@@ -1873,6 +1878,7 @@ static PaError PaAlsaStreamComponent_Ini
 {
     PaError result = paNoError;
     PaSampleFormat userSampleFormat = params->sampleFormat, hostSampleFormat = paNoError;
+    snd_pcm_info_t* pcmInfo;
     assert( params->channelCount > 0 );
 
     /* Make sure things have an initial value */
@@ -1900,6 +1906,9 @@ static PaError PaAlsaStreamComponent_Ini
     self->device = params->device;
 
     PA_ENSURE( AlsaOpen( &alsaApi->baseHostApiRep, params, streamDir, &self->pcm ) );
+
+    snd_pcm_info_alloca( &pcmInfo );
+    self->card = snd_pcm_info_get_card( pcmInfo );
     self->nfds = alsa_snd_pcm_poll_descriptors_count( self->pcm );
 
     PA_ENSURE( hostSampleFormat = PaUtil_SelectClosestAvailableFormat( GetAvailableFormats( self->pcm ), userSampleFormat ) );
@@ -4605,9 +4614,7 @@ PaError PaAlsa_GetStreamInputCard( PaStr
     /* XXX: More descriptive error? */
     PA_UNLESS( stream->capture.pcm, paDeviceUnavailable );
 
-    alsa_snd_pcm_info_alloca( &pcmInfo );
-    PA_ENSURE( alsa_snd_pcm_info( stream->capture.pcm, pcmInfo ) );
-    *card = alsa_snd_pcm_info_get_card( pcmInfo );
+    *card = stream->capture.card;
 
 error:
     return result;
@@ -4624,9 +4631,7 @@ PaError PaAlsa_GetStreamOutputCard( PaSt
     /* XXX: More descriptive error? */
     PA_UNLESS( stream->playback.pcm, paDeviceUnavailable );
 
-    alsa_snd_pcm_info_alloca( &pcmInfo );
-    PA_ENSURE( alsa_snd_pcm_info( stream->playback.pcm, pcmInfo ) );
-    *card = alsa_snd_pcm_info_get_card( pcmInfo );
+    *card = stream->playback.card;
 
 error:
     return result;
