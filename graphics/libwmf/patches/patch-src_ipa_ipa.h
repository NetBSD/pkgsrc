$NetBSD: patch-src_ipa_ipa.h,v 1.1.2.2 2015/07/26 19:49:47 tron Exp $

CVE-2015-4588 - Heap-based buffer overflow in the DecodeImage function in libwmf
0.2.8.4 allows remote attackers to cause a denial of service (crash) or possibly
execute arbitrary code via a crafted "run-length count" in an image in a WMF
file.

--- src/ipa/ipa.h.orig	2015-07-17 00:40:28.000000000 +0000
+++ src/ipa/ipa.h
@@ -48,7 +48,7 @@ static int            ReadBlobByte (BMPS
 static unsigned short ReadBlobLSBShort (BMPSource*);
 static unsigned long  ReadBlobLSBLong (BMPSource*);
 static long           TellBlob (BMPSource*);
-static void           DecodeImage (wmfAPI*,wmfBMP*,BMPSource*,unsigned int,unsigned char*);
+static int            DecodeImage (wmfAPI*,wmfBMP*,BMPSource*,unsigned int,unsigned char*);
 static void           ReadBMPImage (wmfAPI*,wmfBMP*,BMPSource*);
 static int            ExtractColor (wmfAPI*,wmfBMP*,wmfRGB*,unsigned int,unsigned int);
 static void           SetColor (wmfAPI*,wmfBMP*,wmfRGB*,unsigned char,unsigned int,unsigned int);
