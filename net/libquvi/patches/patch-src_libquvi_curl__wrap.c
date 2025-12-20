$NetBSD: patch-src_libquvi_curl__wrap.c,v 1.1 2025/12/20 15:58:11 nia Exp $

Include <string.h> for strdup.

--- src/libquvi/curl_wrap.c.orig	2025-12-20 15:30:59.897689101 +0000
+++ src/libquvi/curl_wrap.c
@@ -20,6 +20,7 @@
 #include "config.h"
 
 #include <stdlib.h>
+#include <string.h>
 #include <memory.h>
 #include <assert.h>
 
