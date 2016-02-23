$NetBSD: patch-src_util_strndup.c,v 1.1 2016/02/23 11:16:55 jperkin Exp $

Provide compat strndup for older Darwin.

--- src/util/strndup.c.orig	2016-01-22 15:44:31.000000000 +0000
+++ src/util/strndup.c
@@ -21,7 +21,7 @@
  * IN THE SOFTWARE.
  */
 
-#if defined(_WIN32)
+#if defined(_WIN32) || (defined(__APPLE__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__-0 < 1070)
 #include <stdlib.h>
 #include <string.h>
 #include "strndup.h"
@@ -35,7 +35,14 @@ strndup(const char *str, size_t max)
    if (!str)
       return NULL;
 
+#if defined(__APPLE__)
+   for (n = 0; n < max; n++, str++) {
+      if (!*str)
+          break;
+   }
+#else
    n = strnlen(str, max);
+#endif
    ptr = (char *) calloc(n + 1, sizeof(char));
    if (!ptr)
       return NULL;
