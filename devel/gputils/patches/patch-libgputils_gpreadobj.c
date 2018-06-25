$NetBSD: patch-libgputils_gpreadobj.c,v 1.2 2018/06/25 14:01:45 bouyer Exp $

Be more paranoid about input, pursuant to a build failure in sdcc3
that seems to involve gplib trying to allocate gigs of memory.

--- ./libgputils/gpreadobj.c.orig	2016-08-06 11:44:18.000000000 +0200
+++ ./libgputils/gpreadobj.c	2018-06-25 14:41:31.504470855 +0200
@@ -712,6 +712,14 @@
   /* determine the size of the file */
   fstat(fileno(infile), &statbuf);
   file->size = statbuf.st_size;
+  /* just in case */
+  if (file->size < 0) {
+    gp_error("File \"%s\" size is negative.", File_name);
+  }
+  if (file->size > 100*1024*1024) {
+    gp_error("File \"%s\" size %ld is unreasonably large.", File_name,
+            file->size);
+  }
 
   /* read the object file into memory */
   file->file = (uint8_t *)GP_Malloc(file->size);
