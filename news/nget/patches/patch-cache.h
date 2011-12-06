$NetBSD: patch-cache.h,v 1.1 2011/12/06 19:51:07 joerg Exp $

--- cache.h.orig	2011-12-06 17:04:06.000000000 +0000
+++ cache.h
@@ -23,6 +23,7 @@
 #endif
 #include <sys/types.h>
 #include <ctype.h>
+#include <climits>
 #include <string>
 #include <map>
 #include "_hash_map.h"
