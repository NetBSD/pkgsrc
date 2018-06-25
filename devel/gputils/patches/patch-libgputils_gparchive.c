$NetBSD: patch-libgputils_gparchive.c,v 1.2 2018/06/25 14:01:45 bouyer Exp $

Be more paranoid about input, pursuant to a build failure in sdcc3
that seems to involve gplib trying to allocate gigs of memory.

--- libgputils/gparchive.c.orig	2016-08-12 15:14:27.000000000 +0200
+++ libgputils/gparchive.c	2018-06-25 14:40:35.697419998 +0200
@@ -378,10 +378,18 @@
 
     /* read the object file or symbol index into memory */
     sscanf(new->header.ar_size, "%il", &object_size);
+    if (object_size < 0) {
+      gp_error("bad archive \"%s\" (negative entry size)", File_name);
+    }
+    /* sanity check */
+    if (object_size > 100*1024*1024) {
+      gp_error("bad archive \"%s\" (unreasonable entry size %d)", File_name,
+              object_size);
+    }
     new->data.size = object_size;
     new->data.file = (uint8_t *)GP_Malloc(object_size);
     if (fread(new->data.file, sizeof(char), object_size, infile) != object_size) {
-      gp_error("bad archive \"%s\"", File_name);
+      gp_error("bad archive \"%s\" (read error)", File_name);
     }
 
     /* insert the new member in the archive list */
