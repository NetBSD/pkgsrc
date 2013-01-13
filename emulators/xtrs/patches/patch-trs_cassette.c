$NetBSD: patch-trs_cassette.c,v 1.2 2013/01/13 20:54:31 is Exp $

--- trs_cassette.c.orig	2008-06-26 04:40:13.000000000 +0000
+++ trs_cassette.c
@@ -234,15 +234,19 @@ static long wave_dataid_offset = WAVE_DA
 static long wave_datasize_offset = WAVE_DATASIZE_OFFSET;
 static long wave_data_offset = WAVE_DATA_OFFSET;
 
+#if HAVE_OSS
 /* Orchestra 80/85/90 stuff */
 static int orch90_left = 128, orch90_right = 128;
+#endif
 
 #if SB_SOUND
 /* ioport of the SoundBlaster command register. 0 means none */
 static unsigned char sb_cassette_volume[4];
 static unsigned char sb_sound_volume[2];
 #endif /*SB_SOUND*/
+#if SB_SOUND || OSS_SOUND
 static unsigned int sb_address=0;
+#endif
 static int sb_volume = 0;
 
 /* Put a 2-byte quantity to a file in little-endian order */
@@ -1221,11 +1225,13 @@ trs_sound_out(int value)
 #endif
 }
 
+#if HAVE_OSS
 static void
 orch90_flush(int dummy)
 {
   trs_orch90_out(0, FLUSH);
 }
+#endif
 
 /* Orchestra 85/90 */
 /* Not supported in obsolescent SB_SOUND mode */
