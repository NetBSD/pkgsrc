$NetBSD: patch-coders_tiff.c,v 1.1 2012/03/30 03:50:47 taca Exp $

* Fix for CVE-2012-1798.

--- coders/tiff.c.orig	2012-02-14 00:43:58.000000000 +0000
+++ coders/tiff.c
@@ -647,7 +647,7 @@ static void TIFFGetEXIFProperties(TIFF *
         ascii=(char *) NULL;
         if ((TIFFGetField(tiff,exif_info[i].tag,&ascii,&sans,&sans) != 0) &&
             (ascii != (char *) NULL) && (*ascii != '\0'))
-          (void) CopyMagickMemory(value,ascii,MaxTextExtent);
+          (void) CopyMagickString(value,ascii,MaxTextExtent);
         break;
       }
       case TIFF_SHORT:
