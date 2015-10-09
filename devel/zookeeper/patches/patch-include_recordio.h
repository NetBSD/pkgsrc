$NetBSD: patch-include_recordio.h,v 1.1 2015/10/09 13:59:56 fhajny Exp $

SunOS has htonll since OpenSolaris.
--- src/c/include/recordio.h.orig	2014-02-20 10:14:08.000000000 +0000
+++ src/c/include/recordio.h
@@ -73,7 +73,10 @@ void close_buffer_iarchive(struct iarchi
 char *get_buffer(struct oarchive *);
 int get_buffer_len(struct oarchive *);
 
+#ifndef __sun
+/* Solaris already implements htonll */
 int64_t htonll(int64_t v);
+#endif
 
 #ifdef __cplusplus
 }
