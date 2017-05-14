$NetBSD: patch-gdk-pixbuf_io-ico.c,v 1.1 2017/05/14 12:55:16 spz Exp $

from https://bugzilla.gnome.org/attachment.cgi?id=347366&action=diff
for CVE-2017-6312

--- gdk-pixbuf/io-ico.c.orig	2017-02-27 17:24:19.000000000 +0000
+++ gdk-pixbuf/io-ico.c
@@ -330,10 +330,8 @@ static void DecodeHeader(guchar *Data, g
 			return;
 		}
 
-		/* We know how many bytes are in the "header" part. */
-		State->HeaderSize = entry->DIBoffset + INFOHEADER_SIZE;
-
-		if (State->HeaderSize < 0) {
+		/* Avoid invoking undefined behavior in the State->HeaderSize calculation below */
+		if (entry->DIBoffset > G_MAXINT - INFOHEADER_SIZE) {
 			g_set_error (error,
 			             GDK_PIXBUF_ERROR,
 			             GDK_PIXBUF_ERROR_CORRUPT_IMAGE,
@@ -341,6 +339,9 @@ static void DecodeHeader(guchar *Data, g
 			return;
 		}
 
+		/* We know how many bytes are in the "header" part. */
+		State->HeaderSize = entry->DIBoffset + INFOHEADER_SIZE;
+
 		if (State->HeaderSize>State->BytesInHeaderBuf) {
 			guchar *tmp=g_try_realloc(State->HeaderBuf,State->HeaderSize);
 			if (!tmp) {
