$NetBSD: patch-scipy___lib_src_messagestream.h,v 1.1 2018/06/14 14:29:16 jperkin Exp $

HAVE_OPEN_MEMSTREAM is defined/not defined, not 0/1.

--- scipy/_lib/src/messagestream.h.orig	2018-05-05 17:10:05.000000000 +0000
+++ scipy/_lib/src/messagestream.h
@@ -5,7 +5,7 @@
 
 #include "messagestream_config.h"
 
-#if HAVE_OPEN_MEMSTREAM
+#ifdef HAVE_OPEN_MEMSTREAM
 FILE *messagestream_open_memstream(char **ptr, size_t *sizeloc)
 {
     return open_memstream(ptr, sizeloc);
