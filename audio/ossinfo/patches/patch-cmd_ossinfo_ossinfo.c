$NetBSD: patch-cmd_ossinfo_ossinfo.c,v 1.1 2021/05/09 08:27:21 nia Exp $

XXX: These features are missing from libossaudio.

--- cmd/ossinfo/ossinfo.c.orig	2019-03-06 07:52:21.000000000 +0000
+++ cmd/ossinfo/ossinfo.c
@@ -131,23 +131,35 @@ print_verbose_formats (unsigned long mas
     printf ("      AFMT_MPEG\t- MPEG (MP2/MP3) encoded audio\n");
   if (mask & AFMT_AC3)
     printf ("      AFMT_AC3\t\t- AC3 (Dolby Digital) encoded audio\n");
+#ifdef AFMT_VORBIS
   if (mask & AFMT_VORBIS)
     printf ("      AFMT_VORBIS\t- Vorbis encoded audio\n");
+#endif
   if (mask & AFMT_S32_LE)
     printf ("      AFMT_S32_LE\t- 32 bit signed little endian\n");
   if (mask & AFMT_S32_BE)
     printf ("      AFMT_S32_BE\t- 32 bit signed big endian\n");
+#ifdef AFMT_FLOAT
   if (mask & AFMT_FLOAT)
     printf
       ("      AFMT_FLOAT\t- Single precision floating point (native endianess)\n");
+#endif
+#ifdef AFMT_S24_LE
   if (mask & AFMT_S24_LE)
     printf ("      AFMT_S24_LE\t- 24/32 bit signed little endian\n");
+#endif
+#ifdef AFMT_S24_BE
   if (mask & AFMT_S24_BE)
     printf ("      AFMT_S24_BE\t- 24/32 bit signed big endian\n");
+#endif
+#ifdef AFMT_S24_PACKED
   if (mask & AFMT_S24_PACKED)
     printf ("      AFMT_S24_PACKED\t- 24 bit packed (3 byte)\n");
+#endif
+#ifdef AFMT_SPDIF_RAW
   if (mask & AFMT_SPDIF_RAW)
     printf ("      AFMT_SPDIF_RAW\t- Raw S/PDIF frames\n");
+#endif
 }
 
 static void
@@ -167,15 +179,21 @@ print_engine_info (oss_audioinfo * ainfo
 
   switch (ainfo->busy)
     {
+#ifdef OSS_OPEN_READ
     case OSS_OPEN_READ:
       printf ("Busy (IN) ");
       break;
+#endif
+#ifdef OSS_OPEN_WRITE
     case OSS_OPEN_WRITE:
       printf ("Busy (OUT) ");
       break;
+#endif
+#ifdef OSS_OPEN_READWRITE
     case OSS_OPEN_READWRITE:
       printf ("Busy (IN/OUT) ");
       break;
+#endif
     default:
       printf ("Available for use ");
     }
@@ -278,14 +296,22 @@ print_audio_info (void)
 	printf ("TRIGGER ");
       if (ainfo.caps & PCM_CAP_MMAP)
 	printf ("MMAP ");
+#ifdef PCM_CAP_MULTI
       if (ainfo.caps & PCM_CAP_MULTI)
 	printf ("MULTI ");
+#endif
+#ifdef PCM_CAP_BIND
       if (ainfo.caps & PCM_CAP_BIND)
 	printf ("BIND ");
+#endif
+#ifdef PCM_CAP_VIRTUAL
       if (ainfo.caps & PCM_CAP_VIRTUAL)
 	printf ("VIRTUAL ");
+#endif
+#ifdef PCM_CAP_SHADOW
       if (ainfo.caps & PCM_CAP_SHADOW)
 	printf ("SHADOW ");
+#endif
       if (ainfo.caps & PCM_CAP_HIDDEN)
 	printf ("HIDDEN ");
       printf ("\n");
@@ -395,6 +421,7 @@ print_audio_info (void)
       printf ("    Sample rate source: %d\n", ainfo.rate_source);
 
 
+#ifdef DSP_CH_MASK
       printf ("    Preferred channel configuration: ");
       switch (ainfo.caps & DSP_CH_MASK)
 	{
@@ -411,6 +438,7 @@ print_audio_info (void)
 	  printf ("MULTICH\n");
 	  break;
 	}
+#endif
 
       printf ("    Supported number of channels (min - max): %d - %d\n",
 	      ainfo.min_channels, ainfo.max_channels);
