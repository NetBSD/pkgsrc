$NetBSD: patch-src_osd_osdmini_minifile.c,v 1.1 2015/07/14 20:14:49 wiz Exp $

Implement missing osd_truncate() function.

--- src/osd/osdmini/minifile.c.orig	2015-06-24 09:53:46.000000000 +0000
+++ src/osd/osdmini/minifile.c
@@ -102,6 +102,25 @@ file_error osd_write(osd_file *file, con
 
 
 //============================================================
+//  osd_truncate
+//============================================================
+
+file_error osd_truncate(osd_file *file, UINT64 offset)
+{
+	UINT32 result;
+
+	if (!file)
+		return FILERR_FAILURE;
+
+	result = ftruncate(fileno((FILE *)file), offset);
+	if (!result)
+		return FILERR_FAILURE;
+
+	return FILERR_NONE;
+}
+
+
+//============================================================
 //  osd_rmfile
 //============================================================
 
