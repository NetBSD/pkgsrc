$NetBSD$

Since this is built with C90, and %zu isn't supported then, cast
the size_t argument to unsigned long to match the format.
https://bugzilla.gnome.org/show_bug.cgi?id=766839

--- testlimits.c.orig	2016-02-09 10:17:34.000000000 +0000
+++ testlimits.c
@@ -1284,13 +1284,14 @@ saxTest(const char *filename, size_t lim
         if (fail)
             res = 0;
         else {
-            fprintf(stderr, "Failed to parse '%s' %lu\n", filename, limit);
+            fprintf(stderr, "Failed to parse '%s' %lu\n", filename,
+		    (unsigned long)limit);
             res = 1;
         }
     } else {
         if (fail) {
             fprintf(stderr, "Failed to get failure for '%s' %lu\n",
-                    filename, limit);
+                    filename, (unsigned long)limit);
             res = 1;
         } else
             res = 0;
@@ -1339,7 +1340,7 @@ readerTest(const char *filename, size_t 
                         filename, crazy_indx);
             else
                 fprintf(stderr, "Failed to parse '%s' %lu\n",
-                        filename, limit);
+                        filename, (unsigned long)limit);
             res = 1;
         }
     } else {
@@ -1349,7 +1350,7 @@ readerTest(const char *filename, size_t 
                         filename, crazy_indx);
             else
                 fprintf(stderr, "Failed to get failure for '%s' %lu\n",
-                        filename, limit);
+                        filename, (unsigned long)limit);
             res = 1;
         } else
             res = 0;
