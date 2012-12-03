$NetBSD: patch-src_mp4__header.c,v 1.1 2012/12/03 22:39:05 wiz Exp $

Gentoo patch for mp4v2-2.0 compatibility.
https://bugs.gentoo.org/show_bug.cgi?id=409281

--- src/mp4_header.c.orig	2011-07-04 00:59:21.000000000 +0000
+++ src/mp4_header.c
@@ -204,7 +204,7 @@ gboolean Mp4_Header_Read_File_Info (gcha
     /* Get size of file */
     ETFileInfo->size = Get_File_Size(filename);
 
-    if ((file = MP4Read(filename, 0)) == MP4_INVALID_FILE_HANDLE )
+    if ((file = MP4Read(filename)) == MP4_INVALID_FILE_HANDLE )
     {
         gchar *filename_utf8 = filename_to_display(filename);
         //g_print(_("ERROR while opening file: '%s' (%s)."),filename_utf8,g_strerror(errno));
@@ -218,7 +218,7 @@ gboolean Mp4_Header_Read_File_Info (gcha
     {
         gchar *filename_utf8 = filename_to_display(filename);
         Log_Print(LOG_ERROR,_("ERROR while opening file: '%s' (%s)."),filename_utf8,("Contains no audio track"));
-        MP4Close(file);
+        MP4Close(file, 0);
         g_free(filename_utf8);
         return FALSE;
     }
@@ -243,7 +243,7 @@ gboolean Mp4_Header_Read_File_Info (gcha
     ETFileInfo->mode = MP4GetTrackAudioChannels(file, trackId);
     ETFileInfo->duration = MP4ConvertFromTrackDuration(file, trackId, MP4GetTrackDuration(file, trackId), MP4_SECS_TIME_SCALE);
 
-    MP4Close(file);
+    MP4Close(file, 0);
     return TRUE;
 }
 
