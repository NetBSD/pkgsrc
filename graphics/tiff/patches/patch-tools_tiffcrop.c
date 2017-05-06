$NetBSD$

CVE-2016-10092
http://bugzilla.maptools.org/show_bug.cgi?id=2620
https://github.com/vadz/libtiff/commit/9657bbe3cdce4aaa90e07d50c1c70ae52da0ba6a
Fix double free
http://bugzilla.maptools.org/show_bug.cgi?id=2535
https://github.com/vadz/libtiff/commit/0abd094b6e5079c4d8be733829240491cb230f3d

--- tools/tiffcrop.c.orig	2016-11-19 01:45:30.000000000 +0000
+++ tools/tiffcrop.c
@@ -3698,7 +3698,7 @@ static int readContigStripsIntoBuffer (T
                                   (unsigned long) strip, (unsigned long)rows);
                         return 0;
                 }
-                bufp += bytes_read;
+                bufp += stripsize;
         }
 
         return 1;
@@ -7986,7 +7986,6 @@ writeCroppedImage(TIFF *in, TIFF *out, s
   if (!TIFFWriteDirectory(out))
     {
     TIFFError("","Failed to write IFD for page number %d", pagenum);
-    TIFFClose(out);
     return (-1);
     }
 
