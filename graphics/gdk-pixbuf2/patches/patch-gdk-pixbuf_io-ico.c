$NetBSD: patch-gdk-pixbuf_io-ico.c,v 1.2 2017/08/08 16:52:10 adam Exp $

from https://bugzilla.gnome.org/attachment.cgi?id=347366&action=diff
for CVE-2017-6312

--- gdk-pixbuf/io-ico.c.orig	2017-08-07 16:52:44.000000000 +0000
+++ gdk-pixbuf/io-ico.c
@@ -333,10 +333,8 @@ static void DecodeHeader(guchar *Data, g
 	for (l = State->entries; l != NULL; l = g_list_next (l)) {
 		entry = l->data;
 
-		/* We know how many bytes are in the "header" part. */
-		State->HeaderSize = entry->DIBoffset + INFOHEADER_SIZE;
-
-		if (State->HeaderSize < 0) {
+		/* Avoid invoking undefined behavior in the State->HeaderSize calculation below */
+		if (entry->DIBoffset > G_MAXINT - INFOHEADER_SIZE) {
 			g_set_error (error,
 			             GDK_PIXBUF_ERROR,
 			             GDK_PIXBUF_ERROR_CORRUPT_IMAGE,
@@ -344,6 +342,9 @@ static void DecodeHeader(guchar *Data, g
 			return;
 		}
 
+		/* We know how many bytes are in the "header" part. */
+		State->HeaderSize = entry->DIBoffset + INFOHEADER_SIZE;
+
 		if (State->HeaderSize>State->BytesInHeaderBuf) {
 			guchar *tmp=g_try_realloc(State->HeaderBuf,State->HeaderSize);
 			if (!tmp) {
