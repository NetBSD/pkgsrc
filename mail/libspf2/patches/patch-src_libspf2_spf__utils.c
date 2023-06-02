$NetBSD: patch-src_libspf2_spf__utils.c,v 1.1 2023/06/02 15:57:57 schmonz Exp $

Include <string.h> for memset().

--- src/libspf2/spf_utils.c.orig	2021-06-09 05:43:12.000000000 +0000
+++ src/libspf2/spf_utils.c
@@ -25,6 +25,9 @@
 #include <memory.h>
 #endif
 
+#ifdef HAVE_STRING_H
+#include <string.h>
+#endif
 
 
 #include "spf.h"
