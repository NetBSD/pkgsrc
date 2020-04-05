$NetBSD: patch-src_audio_netbsd_SDL__netbsdaudio.c,v 1.4 2020/04/05 16:22:42 nia Exp $

https://bugzilla.libsdl.org/show_bug.cgi?id=5076

--- src/audio/netbsd/SDL_netbsdaudio.c.orig	2020-03-11 01:36:18.000000000 +0000
+++ src/audio/netbsd/SDL_netbsdaudio.c
@@ -261,6 +261,14 @@ NETBSDAUDIO_OpenDevice(_THIS, void *hand
             prinfo->encoding = AUDIO_ENCODING_ULINEAR_BE;
             prinfo->precision = 16;
             break;
+        case AUDIO_S32LSB:
+            prinfo->encoding = AUDIO_ENCODING_SLINEAR_LE;
+            prinfo->precision = 32;
+            break;
+        case AUDIO_S32MSB:
+            prinfo->encoding = AUDIO_ENCODING_SLINEAR_BE;
+            prinfo->precision = 32;
+            break;
         }
         if (prinfo->encoding != AUDIO_ENCODING_NONE) {
             break;
