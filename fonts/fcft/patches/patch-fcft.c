$NetBSD: patch-fcft.c,v 1.1 2026/04/14 12:06:06 kikadf Exp $

* Define bswap_16 on NetBSD
* Check for uselocale before using it

--- fcft.c.orig	2025-12-27 11:27:58.000000000 +0000
+++ fcft.c
@@ -1,7 +1,12 @@
 #include "fcft/fcft.h"
 
 #include <assert.h>
+#if defined(__NetBSD__)
+#include <endian.h>
+#define bswap_16(X) htole16(X)
+#else
 #include <byteswap.h>
+#endif
 #include <locale.h>
 #include <math.h>
 #include <stdbool.h>
@@ -533,7 +538,7 @@ base_pattern_from_name(const char *name,
 {
     /* Fontconfig fails to parse floating point values unless locale
      * (LC_NUMERIC) is e.g C, or en_US.UTF-8 */
-
+#if FCFT_HAVE_USELOCALE
     locale_t c_locale = newlocale(LC_NUMERIC_MASK, "C", (locale_t)0);
     if (c_locale == (locale_t)0) {
         LOG_ERRNO("%s: failed to create temporary locale", name);
@@ -546,12 +551,14 @@ base_pattern_from_name(const char *name,
         freelocale(c_locale);
         return NULL;
     }
-
+#endif
     FcPattern *pattern = FcNameParse((const unsigned char *)name);
 
+#if FCFT_HAVE_USELOCALE
     /* Restore locale */
     uselocale(old_locale);
     freelocale(c_locale);
+#endif
 
     if (pattern == NULL) {
         LOG_ERR("%s: failed to lookup font", name);
