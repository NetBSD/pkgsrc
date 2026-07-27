$NetBSD: patch-libzsync_zsync.c,v 1.1 2026/07/27 15:38:30 ryoon Exp $

* Use calloc properly as calloc(num, size).

--- libzsync/zsync.c.orig	2010-09-19 20:51:53.000000000 +0000
+++ libzsync/zsync.c
@@ -151,7 +151,7 @@ struct zsync_state *zsync_begin(FILE * f) {
     char *safelines = NULL;
 
     /* Allocate memory for the object */
-    struct zsync_state *zs = calloc(sizeof *zs, 1);
+    struct zsync_state *zs = calloc(1, sizeof *zs);
 
     if (!zs)
         return NULL;
@@ -210,7 +210,7 @@ struct zsync_state *zsync_begin(FILE * f) {
             }
             else if (!strcmp(buf, "Blocksize")) {
                 zs->blocksize = atol(p);
-                if (zs->blocksize < 0 || (zs->blocksize & (zs->blocksize - 1))) {
+                if ((zs->blocksize & (zs->blocksize - 1))) {
                     fprintf(stderr, "nonsensical blocksize %ld\n", zs->blocksize);
                     free(zs);
                     return NULL;
@@ -240,7 +240,7 @@ struct zsync_state *zsync_begin(FILE * f) {
 
                 zblock = malloc(nzblocks * sizeof *zblock);
                 if (zblock) {
-                    if (fread(zblock, sizeof *zblock, nzblocks, f) < nzblocks) {
+                    if (fread(zblock, sizeof *zblock, nzblocks, f) < (size_t)nzblocks) {
                         fprintf(stderr, "premature EOF after Z-Map\n");
                         free(zs);
                         return NULL;
@@ -436,7 +436,7 @@ void zsync_progress(const struct zsync_state *zs, long
  * Note that these URLs could be for encoded versions of the target; a 'type'
  * is returned in *type which tells libzsync in later calls what version of the
  * target is being retrieved. */
-const char *const *zsync_get_urls(struct zsync_state *zs, int *n, int *t) {
+char **zsync_get_urls(struct zsync_state *zs, int *n, int *t) {
     if (zs->zmap && zs->nzurl) {
         *n = zs->nzurl;
         *t = 1;
@@ -701,7 +701,7 @@ static int zsync_recompress(struct zsync_state *zs) {
                     p = skip_zhead(buf);
                     skip = 0;
                 }
-                if (fwrite(p, 1, r - (p - buf), zout) != r - (p - buf)) {
+                if (fwrite(p, 1, r - (p - buf), zout) != (size_t)(r - (p - buf))) {
                     perror("fwrite");
                     rc = -1;
                     goto leave_it;
@@ -912,7 +912,7 @@ static int zsync_receive_data_compressed(struct zsync_
  * expected checksum for the corresponding blocks)
  */
 static int zsync_receive_data_compressed(struct zsync_receiver *zr,
-                              const unsigned char *buf, off_t offset,
+                              unsigned char *buf, off_t offset,
                               size_t len) {
     int ret = 0;
     int eoz = 0;
@@ -925,9 +925,9 @@ static int zsync_receive_data_compressed(struct zsync_
     zr->strm.next_in = buf;
     zr->strm.avail_in = len;
 
-    if (zr->strm.total_in == 0 || offset != zr->strm.total_in) {
+    if (zr->strm.total_in == 0 || offset != (off_t)(zr->strm.total_in)) {
         zsync_configure_zstream_for_zdata(zr->zs, &(zr->strm), offset,
-                                          &(zr->outoffset));
+                                          (long long *)(&(zr->outoffset)));
 
         /* On first iteration, we might be reading an incomplete block from zsync's point of view. Limit avail_out so we can stop after doing that and realign with the buffer. */
         zr->strm.avail_out = blocksize - (zr->outoffset % blocksize);
@@ -952,6 +952,7 @@ static int zsync_receive_data_compressed(struct zsync_
         switch (rc) {
         case Z_STREAM_END:
             eoz = 1;
+            /* FALLTHROUGH */
         case Z_BUF_ERROR:
         case Z_OK:
             if (zr->strm.avail_out == 0 || eoz) {
@@ -991,7 +992,7 @@ static int zsync_receive_data_compressed(struct zsync_
  * Returns 0 unless there's an error (e.g. the submitted data doesn't match the
  * expected checksum for the corresponding blocks)
  */
-int zsync_receive_data(struct zsync_receiver *zr, const unsigned char *buf,
+int zsync_receive_data(struct zsync_receiver *zr, unsigned char *buf,
                        off_t offset, size_t len) {
     if (zr->url_type == 1) {
         return zsync_receive_data_compressed(zr, buf, offset, len);
