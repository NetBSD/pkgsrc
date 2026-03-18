$NetBSD: patch-src_mpeg2dec_store.c,v 1.1 2026/03/18 14:38:19 nia Exp $

Fix implicit function declarations.

--- src/mpeg2dec/store.c.orig	2026-03-18 14:13:41.245910157 +0000
+++ src/mpeg2dec/store.c
@@ -29,7 +29,9 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <fcntl.h>
+#include <unistd.h>
 
 #include "config.h"
 #include "global.h"
