$NetBSD: patch-include_safe-ctype.h,v 1.4 2026/10/12 09:10:09 jperkin Exp $

Added by joerg in 2015, it's unclear if this is still required, but at the
same time it's probably harmless, so left until we're sure it can be removed.

--- include/safe-ctype.h.orig	2020-07-24 09:12:20.000000000 +0000
+++ include/safe-ctype.h
@@ -120,6 +120,8 @@ extern const unsigned char  _sch_tolower
    So we include ctype.h here and then immediately redefine its macros.  */
 
 #include <ctype.h>
+
+#ifndef __cplusplus
 #undef isalpha
 #define isalpha(c) do_not_use_isalpha_with_safe_ctype
 #undef isalnum
@@ -146,5 +148,6 @@ extern const unsigned char  _sch_tolower
 #define toupper(c) do_not_use_toupper_with_safe_ctype
 #undef tolower
 #define tolower(c) do_not_use_tolower_with_safe_ctype
+#endif
 
 #endif /* SAFE_CTYPE_H */
