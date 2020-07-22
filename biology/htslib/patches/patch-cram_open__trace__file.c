$NetBSD: patch-cram_open__trace__file.c,v 1.1 2020/07/22 14:50:14 bacon Exp $

# Enhance error message

--- cram/open_trace_file.c.orig	2019-12-19 09:54:30.000000000 +0000
+++ cram/open_trace_file.c
@@ -204,8 +204,9 @@ mFILE *find_file_url(const char *file, c
             goto fail;
         }
     }
-    if (hclose(hf) < 0 || len < 0) {
-        hts_log_warning("Failed to read reference \"%s\": %s", path, strerror(errno));
+    int close_status = hclose(hf);
+    if (close_status < 0 || len < 0) {
+        hts_log_warning("Failed to read reference \"%s\": %s  close_status = %d len = %ld", path, strerror(errno));
         goto fail;
     }
 
