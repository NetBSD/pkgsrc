$NetBSD: patch-ext_phar_tar.c,v 1.1 2012/06/12 14:45:51 taca Exp $

Fix for http://secunia.com/advisories/44335/, also CVE-2012-2386.

--- ext/phar/tar.c.orig	2012-05-08 09:22:27.000000000 +0000
+++ ext/phar/tar.c
@@ -337,6 +337,16 @@ bail:
 			last_was_longlink = 1;
 			/* support the ././@LongLink system for storing long filenames */
 			entry.filename_len = entry.uncompressed_filesize;
+
+			/* Check for overflow - bug 61065 */
+			if (entry.filename_len == UINT_MAX) {
+				if (error) {
+					spprintf(error, 4096, "phar error: \"%s\" is a corrupted tar file (invalid entry size)", fname);
+				}
+				php_stream_close(fp);
+				phar_destroy_phar_data(myphar TSRMLS_CC);
+				return FAILURE;
+			}
 			entry.filename = pemalloc(entry.filename_len+1, myphar->is_persistent);
 
 			read = php_stream_read(fp, entry.filename, entry.filename_len);
