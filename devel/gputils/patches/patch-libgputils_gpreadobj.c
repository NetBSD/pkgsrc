$NetBSD: patch-libgputils_gpreadobj.c,v 1.1 2016/09/14 14:10:50 dholland Exp $

Be more paranoid about input, pursuant to a build failure in sdcc3
that seems to involve gplib trying to allocate gigs of memory.

--- libgputils/gpreadobj.c~	2015-11-23 18:17:01.000000000 +0000
+++ libgputils/gpreadobj.c
@@ -109,6 +109,15 @@ gp_read_file(const char *filename)
   fstat(fileno(infile), &statbuf);
   file->size = statbuf.st_size;
 
+  /* just in case */
+  if (file->size < 0) {
+    gp_error("File \"%s\" size is negative.", filename);
+  }
+  if (file->size > 100*1024*1024) {
+    gp_error("File \"%s\" size %ld is unreasonably large.", filename,
+	     file->size);
+  }
+
   /* read the object file into memory */
   file->file = (unsigned char *)GP_Malloc(file->size);
   n = fread(file->file, 1, file->size, infile);
