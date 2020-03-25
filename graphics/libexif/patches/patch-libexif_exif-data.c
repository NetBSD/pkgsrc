$NetBSD: patch-libexif_exif-data.c,v 1.2 2020/03/25 11:47:23 nia Exp $

Fix for CVE-2017-7544:
https://github.com/libexif/libexif/commit/c39acd1692023b26290778a02a9232c873f9d71a.patch

Fix for CVE-2019-9278:
https://github.com/libexif/libexif/commit/75aa73267fdb1e0ebfbc00369e7312bac43d0566.patch

--- libexif/exif-data.c.orig	2012-07-12 18:31:56.000000000 +0000
+++ libexif/exif-data.c
@@ -191,9 +191,15 @@ exif_data_load_data_entry (ExifData *dat
 		doff = offset + 8;
 
 	/* Sanity checks */
-	if ((doff + s < doff) || (doff + s < s) || (doff + s > size)) {
+	if (doff >= size) {
 		exif_log (data->priv->log, EXIF_LOG_CODE_DEBUG, "ExifData",
-				  "Tag data past end of buffer (%u > %u)", doff+s, size);	
+				  "Tag starts past end of buffer (%u > %u)", doff, size);
+		return 0;
+	}
+
+	if (s > size - doff) {
+		exif_log (data->priv->log, EXIF_LOG_CODE_DEBUG, "ExifData",
+				  "Tag data goes past end of buffer (%u > %u)", doff+s, size);
 		return 0;
 	}
 
@@ -255,6 +261,12 @@ exif_data_save_data_entry (ExifData *dat
 			exif_mnote_data_set_offset (data->priv->md, *ds - 6);
 			exif_mnote_data_save (data->priv->md, &e->data, &e->size);
 			e->components = e->size;
+			if (exif_format_get_size (e->format) != 1) {
+				/* e->format is taken from input code,
+				 * but we need to make sure it is a 1 byte
+				 * entity due to the multiplication below. */
+				e->format = EXIF_FORMAT_UNDEFINED;
+			}
 		}
 	}
 
@@ -308,13 +320,14 @@ exif_data_load_data_thumbnail (ExifData 
 			       unsigned int ds, ExifLong o, ExifLong s)
 {
 	/* Sanity checks */
-	if ((o + s < o) || (o + s < s) || (o + s > ds) || (o > ds)) {
-		exif_log (data->priv->log, EXIF_LOG_CODE_DEBUG, "ExifData",
-			  "Bogus thumbnail offset (%u) or size (%u).",
-			  o, s);
+	if (o >= ds) {
+		exif_log (data->priv->log, EXIF_LOG_CODE_DEBUG, "ExifData", "Bogus thumbnail offset (%u).", o);
+		return;
+	}
+	if (s > ds - o) {
+		exif_log (data->priv->log, EXIF_LOG_CODE_DEBUG, "ExifData", "Bogus thumbnail size (%u), max would be %u.", s, ds-o);
 		return;
 	}
-
 	if (data->data) 
 		exif_mem_free (data->priv->mem, data->data);
 	if (!(data->data = exif_data_alloc (data, s))) {
@@ -903,7 +916,7 @@ exif_data_load_data (ExifData *data, con
 	exif_log (data->priv->log, EXIF_LOG_CODE_DEBUG, "ExifData", 
 		  "IFD 0 at %i.", (int) offset);
 
-	/* Sanity check the offset, being careful about overflow */
+	/* ds is restricted to 16 bit above, so offset is restricted too, and offset+8 should not overflow. */
 	if (offset > ds || offset + 6 + 2 > ds)
 		return;
 
@@ -912,6 +925,7 @@ exif_data_load_data (ExifData *data, con
 
 	/* IFD 1 offset */
 	n = exif_get_short (d + 6 + offset, data->priv->order);
+	/* offset < 2<<16, n is 16 bit at most, so this op will not overflow */
 	if (offset + 6 + 2 + 12 * n + 4 > ds)
 		return;
 
@@ -920,8 +934,8 @@ exif_data_load_data (ExifData *data, con
 		exif_log (data->priv->log, EXIF_LOG_CODE_DEBUG, "ExifData",
 			  "IFD 1 at %i.", (int) offset);
 
-		/* Sanity check. */
-		if (offset > ds || offset + 6 > ds) {
+		/* Sanity check. ds is ensured to be above 6 above, offset is 16bit */
+		if (offset > ds - 6) {
 			exif_log (data->priv->log, EXIF_LOG_CODE_CORRUPT_DATA,
 				  "ExifData", "Bogus offset of IFD1.");
 		} else {
