$NetBSD: patch-uulib_uulib.c,v 1.1 2019/11/16 22:22:45 rhialto Exp $

Use the full length of the buffer to read (potentially long)
header lines. Patch taken from "nget+uulib v0.27.1 tarball"
at http://nget.sourceforge.net/.

--- uulib/uulib.c.orig	2003-09-29 23:27:47.000000000 +0000
+++ uulib/uulib.c
@@ -1103,9 +1103,9 @@ UUInfoFile (uulist *thefile, void *opaqu
 
   while (!feof (inpfile) && 
 	 (uu_fast_scanning || ftell(inpfile) < maxpos)) {
-    if (_FP_fgets (uugen_inbuffer, 511, inpfile) == NULL)
+    if (_FP_fgets (uugen_inbuffer, 1023, inpfile) == NULL)
       break;
-    uugen_inbuffer[511] = '\0';
+    uugen_inbuffer[1023] = '\0';
 
     if (ferror (inpfile))
       break;
