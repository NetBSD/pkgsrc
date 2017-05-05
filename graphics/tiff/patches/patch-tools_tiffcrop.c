$NetBSD$

Fix for CVE-2016-10092, ref. http://bugzilla.maptools.org/show_bug.cgi?id=2620
and
https://github.com/vadz/libtiff/commit/9657bbe3cdce4aaa90e07d50c1c70ae52da0ba6a

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
