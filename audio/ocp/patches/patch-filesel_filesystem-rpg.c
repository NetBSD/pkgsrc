$NetBSD: patch-filesel_filesystem-rpg.c,v 1.1 2024/03/17 17:34:06 nia Exp $

filesystem-rpg.c:613:4: error: a label can only be part of a statement
and a declaration is not a statement

--- filesel/filesystem-rpg.c.orig	2024-03-17 16:47:27.071188695 +0000
+++ filesel/filesystem-rpg.c
@@ -609,10 +609,13 @@ static int rpg_dir_readdir_iterate (ocpd
 		self->dir->owner->archive_filehandle->seek_set (self->dir->owner->archive_filehandle, self->nextheader_offset);
 		if (self->dir->owner->archive_filehandle->read (self->dir->owner->archive_filehandle, header, sizeof (header)) < 6)
 		{
-finished:
 			const char *filename;
-			uint8_t *metadata = 0;
-			size_t metadatasize = 0;
+			uint8_t *metadata;
+			size_t metadatasize;
+
+finished:
+			metadata = NULL;
+			metadatasize = 0;
 
 			self->dir->owner->ready = 1;
 			rpg_instance_encode_blob (self->dir->owner, &metadata, &metadatasize);
