$NetBSD: patch-Source_Metadata_XTIFF.cpp,v 1.1 2020/05/14 16:42:14 nia Exp $

Unbundle image libraries.

--- Source/Metadata/XTIFF.cpp.orig	2015-03-04 00:07:10.000000000 +0000
+++ Source/Metadata/XTIFF.cpp
@@ -29,13 +29,18 @@
 #pragma warning (disable : 4786) // identifier was truncated to 'number' characters
 #endif
 
-#include "../LibTIFF4/tiffiop.h"
+#include <tiffio.h>
 
 #include "FreeImage.h"
 #include "Utilities.h"
 #include "FreeImageTag.h"
 #include "FIRational.h"
 
+extern "C"
+{
+    int _TIFFDataSize(TIFFDataType type);
+}
+
 // ----------------------------------------------------------
 //   Extended TIFF Directory GEO Tag Support
 // ----------------------------------------------------------
@@ -224,6 +229,33 @@ tiff_write_geotiff_profile(TIFF *tif, FI
 //   TIFF EXIF tag reading & writing
 // ----------------------------------------------------------
 
+static uint32 exif_tag_ids[] = {
+  EXIFTAG_EXPOSURETIME, EXIFTAG_FNUMBER, EXIFTAG_EXPOSUREPROGRAM,
+  EXIFTAG_SPECTRALSENSITIVITY, EXIFTAG_ISOSPEEDRATINGS, EXIFTAG_OECF,
+  EXIFTAG_EXIFVERSION, EXIFTAG_DATETIMEORIGINAL, EXIFTAG_DATETIMEDIGITIZED,
+  EXIFTAG_COMPONENTSCONFIGURATION, EXIFTAG_COMPRESSEDBITSPERPIXEL,
+  EXIFTAG_SHUTTERSPEEDVALUE, EXIFTAG_APERTUREVALUE,
+  EXIFTAG_BRIGHTNESSVALUE, EXIFTAG_EXPOSUREBIASVALUE,
+  EXIFTAG_MAXAPERTUREVALUE, EXIFTAG_SUBJECTDISTANCE, EXIFTAG_METERINGMODE,
+  EXIFTAG_LIGHTSOURCE, EXIFTAG_FLASH, EXIFTAG_FOCALLENGTH,
+  EXIFTAG_SUBJECTAREA, EXIFTAG_MAKERNOTE, EXIFTAG_USERCOMMENT,
+  EXIFTAG_SUBSECTIME, EXIFTAG_SUBSECTIMEORIGINAL,
+  EXIFTAG_SUBSECTIMEDIGITIZED, EXIFTAG_FLASHPIXVERSION, EXIFTAG_COLORSPACE,
+  EXIFTAG_PIXELXDIMENSION, EXIFTAG_PIXELYDIMENSION,
+  EXIFTAG_RELATEDSOUNDFILE, EXIFTAG_FLASHENERGY,
+  EXIFTAG_SPATIALFREQUENCYRESPONSE, EXIFTAG_FOCALPLANEXRESOLUTION,
+  EXIFTAG_FOCALPLANEYRESOLUTION, EXIFTAG_FOCALPLANERESOLUTIONUNIT,
+  EXIFTAG_SUBJECTLOCATION, EXIFTAG_EXPOSUREINDEX, EXIFTAG_SENSINGMETHOD,
+  EXIFTAG_FILESOURCE, EXIFTAG_SCENETYPE, EXIFTAG_CFAPATTERN,
+  EXIFTAG_CUSTOMRENDERED, EXIFTAG_EXPOSUREMODE, EXIFTAG_WHITEBALANCE,
+  EXIFTAG_DIGITALZOOMRATIO, EXIFTAG_FOCALLENGTHIN35MMFILM,
+  EXIFTAG_SCENECAPTURETYPE, EXIFTAG_GAINCONTROL, EXIFTAG_CONTRAST,
+  EXIFTAG_SATURATION, EXIFTAG_SHARPNESS, EXIFTAG_DEVICESETTINGDESCRIPTION,
+  EXIFTAG_SUBJECTDISTANCERANGE, EXIFTAG_GAINCONTROL, EXIFTAG_GAINCONTROL,
+  EXIFTAG_IMAGEUNIQUEID
+};
+static int nExifTags = sizeof(exif_tag_ids) / sizeof(exif_tag_ids[0]);
+
 /**
 Read a single Exif tag
 
@@ -575,45 +607,11 @@ tiff_read_exif_tags(TIFF *tif, TagLib::M
 
 	// loop over all Core Directory Tags
 	// ### uses private data, but there is no other way
+	// -> Fedora: Best we can do without private headers is to hard-code a list of known EXIF tags and read those
 	if(md_model == TagLib::EXIF_MAIN) {
-		const TIFFDirectory *td = &tif->tif_dir;
-
-		uint32 lastTag = 0;	//<- used to prevent reading some tags twice (as stored in tif_fieldinfo)
-
-		for (int fi = 0, nfi = (int)tif->tif_nfields; nfi > 0; nfi--, fi++) {
-			const TIFFField *fld = tif->tif_fields[fi];
-
-			const uint32 tag_id = TIFFFieldTag(fld);
-
-			if(tag_id == lastTag) {
-				continue;
-			}
-
-			// test if tag value is set
-			// (lifted directly from LibTiff _TIFFWriteDirectory)
-
-			if( fld->field_bit == FIELD_CUSTOM ) {
-				int is_set = FALSE;
-
-				for(int ci = 0; ci < td->td_customValueCount; ci++ ) {
-					is_set |= (td->td_customValues[ci].info == fld);
-				}
-
-				if( !is_set ) {
-					continue;
-				}
-
-			} else if(!TIFFFieldSet(tif, fld->field_bit)) {
-				continue;
-			}
-
-			// process *all* other tags (some will be ignored)
-
-			tiff_read_exif_tag(tif, tag_id, dib, md_model);
-
-			lastTag = tag_id;
+		for (int i = 0; i < nExifTags; ++i) {
+			tiff_read_exif_tag(tif, exif_tag_ids[i], dib, md_model);
 		}
-
 	}
 
 	return TRUE;
@@ -723,10 +721,9 @@ tiff_write_exif_tags(TIFF *tif, TagLib::
 	
 	TagLib& tag_lib = TagLib::instance();
 	
-	for (int fi = 0, nfi = (int)tif->tif_nfields; nfi > 0; nfi--, fi++) {
-		const TIFFField *fld = tif->tif_fields[fi];
-		
-		const uint32 tag_id = TIFFFieldTag(fld);
+	for (int fi = 0; fi < nExifTags; fi++) {
+		const uint32 tag_id = exif_tag_ids[fi];
+		const TIFFField *fld = TIFFFieldWithTag(tif, tag_id);
 
 		if(skip_write_field(tif, tag_id)) {
 			// skip tags that are already handled by the LibTIFF writing process
