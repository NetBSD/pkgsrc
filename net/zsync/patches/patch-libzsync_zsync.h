$NetBSD: patch-libzsync_zsync.h,v 1.1 2026/07/27 15:38:30 ryoon Exp $

--- libzsync/zsync.h.orig	2010-09-16 17:17:49.000000000 +0000
+++ libzsync/zsync.h
@@ -58,7 +58,7 @@ int zsync_submit_source_file(struct zsync_state* zs, F
  * (the URL pointers are still referenced by the library, and are valid only until zsync_end).
  */
 
-const char * const * zsync_get_urls(struct zsync_state* zs, int* n, int* t);
+char ** zsync_get_urls(struct zsync_state* zs, int* n, int* t);
 
 /* zsync_needed_byte_ranges - get the byte ranges needed from a URL.
  * Returns the number of ranges in *num, and a malloc'd array (to be freed 
@@ -91,5 +91,5 @@ void zsync_end_receive(struct zsync_receiver* zr);
 
 /* Supply data buf of length len received corresponding to offset offset from the URL.
  * Returns 0 for success; if not, you should not submit more data. */
-int zsync_receive_data(struct zsync_receiver* zr, const unsigned char* buf, off_t offset, size_t len);
+int zsync_receive_data(struct zsync_receiver* zr, unsigned char* buf, off_t offset, size_t len);
 
