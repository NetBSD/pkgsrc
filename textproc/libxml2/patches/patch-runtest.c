$NetBSD$

Since this is built with C90, and %zu isn't supported then, cast
the size_t argument to long to match the format.
https://bugzilla.gnome.org/show_bug.cgi?id=766839

--- runtest.c.orig	2016-05-23 07:25:25.000000000 +0000
+++ runtest.c
@@ -688,7 +688,7 @@ static int compareFileMem(const char *fi
     }
     if (info.st_size != size) {
         fprintf(stderr, "file %s is %ld bytes, result is %d bytes\n",
-	        filename, info.st_size, size);
+	        filename, (long)info.st_size, size);
         return(-1);
     }
     fd = open(filename, RD_FLAGS);
