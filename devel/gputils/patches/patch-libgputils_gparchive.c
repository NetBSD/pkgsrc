$NetBSD: patch-libgputils_gparchive.c,v 1.1 2016/09/14 14:10:50 dholland Exp $

Be more paranoid about input, pursuant to a build failure in sdcc3
that seems to involve gplib trying to allocate gigs of memory.

--- libgputils/gparchive.c~	2015-12-12 14:47:51.000000000 +0000
+++ libgputils/gparchive.c
@@ -333,10 +333,18 @@ gp_archive_read(const char *filename)
 
     /* read the object file or symbol index into memory */
     sscanf(new->header.ar_size, "%il", &object_size);
+    if (object_size < 0) {
+      gp_error("bad archive \"%s\" (negative entry size)", filename);
+    }
+    /* sanity check */
+    if (object_size > 100*1024*1024) {
+      gp_error("bad archive \"%s\" (unreasonable entry size %d)", filename,
+	       object_size);
+    }
     new->data.size = object_size;
     new->data.file = (unsigned char *)GP_Malloc(object_size);
     if (fread(new->data.file, sizeof(char), object_size, infile) != object_size) {
-      gp_error("bad archive \"%s\"", filename);
+      gp_error("bad archive \"%s\" (read error)", filename);
     }
 
     /* insert the new member in the archive list */
