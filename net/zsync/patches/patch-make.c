$NetBSD: patch-make.c,v 1.1 2026/07/27 15:38:30 ryoon Exp $

--- make.c.orig	2010-09-16 17:17:49.000000000 +0000
+++ make.c
@@ -441,7 +441,7 @@ static char *encode_filename(const char *fname) {
     {   /* pass through string character by character */
         int i, j;
         for (i = j = 0; fname[i]; i++) {
-            if (!isalnum(fname[i]))
+            if (!isalnum((unsigned char)(fname[i])))
                 cmd[j++] = '\\';
             cmd[j++] = fname[i];
         }
@@ -718,7 +718,7 @@ int main(int argc, char **argv) {
     read_stream_write_blocksums(instream, tf);
 
     {   /* Decide how long a rsum hash and checksum hash per block we need for this file */
-        seq_matches = len > blocksize ? 2 : 1;
+        seq_matches = len > (off_t)blocksize ? 2 : 1;
         rsum_len = ceil(((log(len) + log(blocksize)) / log(2) - 8.6) / seq_matches / 8);
 
         /* min and max lengths of rsums to store */
@@ -836,7 +836,7 @@ int main(int argc, char **argv) {
                     fprintf(fout, "MTime: %s\n", buf);
             }
             else {
-                fprintf(stderr, "error converting %d to struct tm\n", mtime);
+                fprintf(stderr, "error converting %ld to struct tm\n", mtime);
             }
         }
     }
