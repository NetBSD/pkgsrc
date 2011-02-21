$NetBSD: patch-ext_exif_exif.c,v 1.1 2011/02/21 16:25:33 taca Exp $

Catch up to r308362 from PHP's repogitry for SA43328.

--- ext/exif/exif.c.orig	2010-01-03 09:23:27.000000000 +0000
+++ ext/exif/exif.c
@@ -40,6 +40,16 @@
 #include "php.h"
 #include "ext/standard/file.h"
 
+#ifdef HAVE_STDINT_H
+# include <stdint.h>
+#endif
+#ifdef HAVE_INTTYPES_H
+# include <inttypes.h>
+#endif
+#ifdef PHP_WIN32
+# include "win32/php_stdint.h"
+#endif
+
 #if HAVE_EXIF
 
 /* When EXIF_DEBUG is defined the module generates a lot of debug messages
@@ -2826,6 +2836,7 @@ static int exif_process_IFD_TAG(image_in
 	int tag, format, components;
 	char *value_ptr, tagname[64], cbuf[32], *outside=NULL;
 	size_t byte_count, offset_val, fpos, fgot;
+	int64_t byte_count_signed;
 	xp_field_type *tmp_xp;
 #ifdef EXIF_DEBUG
 	char *dump_data;
@@ -2850,13 +2861,20 @@ static int exif_process_IFD_TAG(image_in
 		/*return TRUE;*/
 	}
 
-	byte_count = components * php_tiff_bytes_per_format[format];
+	if (components < 0) {
+		exif_error_docref("exif_read_data#error_ifd" EXIFERR_CC, ImageInfo, E_WARNING, "Process tag(x%04X=%s): Illegal components(%ld)", tag, exif_get_tagname(tag, tagname, -12, tag_table TSRMLS_CC), components);
+		return FALSE;
+	}
+
+	byte_count_signed = (int64_t)components * php_tiff_bytes_per_format[format];
 
-	if ((ssize_t)byte_count < 0) {
-		exif_error_docref("exif_read_data#error_ifd" EXIFERR_CC, ImageInfo, E_WARNING, "Process tag(x%04X=%s): Illegal byte_count(%ld)", tag, exif_get_tagname(tag, tagname, -12, tag_table TSRMLS_CC), byte_count);
+	if (byte_count_signed < 0 || (byte_count_signed > INT32_MAX)) {
+		exif_error_docref("exif_read_data#error_ifd" EXIFERR_CC, ImageInfo, E_WARNING, "Process tag(x%04X=%s): Illegal byte_count", tag, exif_get_tagname(tag, tagname, -12, tag_table TSRMLS_CC));
 		return FALSE;
 	}
 
+	byte_count = (size_t)byte_count_signed;
+
 	if (byte_count > 4) {
 		offset_val = php_ifd_get32u(dir_entry+8, ImageInfo->motorola_intel);
 		/* If its bigger than 4 bytes, the dir entry contains an offset. */
@@ -2921,6 +2939,7 @@ static int exif_process_IFD_TAG(image_in
 		efree(dump_data);
 	}
 #endif
+
 	if (section_index==SECTION_THUMBNAIL) {
 		if (!ImageInfo->Thumbnail.data) {
 			switch(tag) {
