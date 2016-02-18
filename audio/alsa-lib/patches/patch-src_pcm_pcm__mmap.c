$NetBSD: patch-src_pcm_pcm__mmap.c,v 1.2 2016/02/18 15:15:57 wiz Exp $

--- src/pcm/pcm_mmap.c.orig	2015-11-09 07:39:18.000000000 +0000
+++ src/pcm/pcm_mmap.c
@@ -20,7 +20,7 @@
 
 #include "config.h"
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 #include <sys/poll.h>
 #include <sys/mman.h>
