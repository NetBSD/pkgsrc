$NetBSD: patch-src_pcm_pcm__mmap.c,v 1.3 2021/05/12 14:12:13 ryoon Exp $

--- src/pcm/pcm_mmap.c.orig	2020-06-29 10:51:08.000000000 +0000
+++ src/pcm/pcm_mmap.c
@@ -20,7 +20,7 @@
 
 #include "config.h"
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 #include <poll.h>
 #include <sys/mman.h>
