$NetBSD: patch-queuedir.c,v 1.1 2017/08/21 18:16:29 schmonz Exp $

Build on systems without O_DIRECTORY.

--- queuedir.c.orig	2015-02-12 14:10:37.000000000 +0000
+++ queuedir.c
@@ -166,6 +166,9 @@ const response* queuedir_message_end(int
     return &resp_writeerr;
   }
   if (dosync) {
+#ifndef O_DIRECTORY
+#define O_DIRECTORY O_RDONLY
+#endif
     if ((fd = open(destpath.s, O_DIRECTORY | O_RDONLY)) < 0) {
       queuedir_reset();
       return &resp_internal;
