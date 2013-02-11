$NetBSD: patch-src_wavpack__tag.c,v 1.1 2013/02/11 08:56:42 wiz Exp $

Allow compilation with c90 compiler.

--- src/wavpack_tag.c.orig	2013-02-05 22:42:37.000000000 +0000
+++ src/wavpack_tag.c
@@ -82,15 +82,15 @@ gboolean Wavpack_Tag_Write_File (FILE *f
  */
 gboolean Wavpack_Tag_Read_File_Tag (gchar *filename, File_Tag *FileTag)
 {
-    if (!filename || !FileTag)
-        return FALSE;
-
     WavpackContext *wpc;
     gchar *field, *field2;
     guint length;
 
     int open_flags = OPEN_TAGS;
 
+    if (!filename || !FileTag)
+        return FALSE;
+
     wpc = WavpackOpenFileInput(filename, NULL, open_flags, 0);
 
     if ( wpc == NULL ) {
@@ -271,17 +271,20 @@ gboolean Wavpack_Tag_Read_File_Tag (gcha
 
 gboolean Wavpack_Tag_Write_File_Tag (ET_File *ETFile)
 {
-    if (!ETFile || !ETFile->FileTag)
-        return FALSE;
-
     WavpackContext *wpc;
 
-    gchar    *filename = ((File_Name *)((GList *)ETFile->FileNameCur)->data)->value;
-    File_Tag *FileTag  = (File_Tag *)ETFile->FileTag->data;
+    gchar    *filename;
+    File_Tag *FileTag;
     gchar    *buffer;
 
     int open_flags = OPEN_EDIT_TAGS;
 
+    if (!ETFile || !ETFile->FileTag)
+        return FALSE;
+
+    filename = ((File_Name *)((GList *)ETFile->FileNameCur)->data)->value;
+    FileTag = (File_Tag *)ETFile->FileTag->data;
+
     wpc = WavpackOpenFileInput(filename, NULL, open_flags, 0);
 
     if ( wpc == NULL ) {
