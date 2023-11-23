$NetBSD: patch-src_pcm_pcm__mmap.c,v 1.4 2023/11/23 16:15:04 ryoon Exp $

--- src/pcm/pcm_mmap.c.orig	2023-05-04 07:16:16.000000000 +0000
+++ src/pcm/pcm_mmap.c
@@ -22,6 +22,8 @@
 #include <stdio.h>
 #if HAVE_MALLOC_H
 #include <malloc.h>
+#else
+#include <stdlib.h>
 #endif
 #include <string.h>
 #include <poll.h>
