$NetBSD: patch-include_safe-ctype.h,v 1.1 2026/04/20 03:49:24 js Exp $

--- include/safe-ctype.h.orig	2026-04-20 01:37:46.426135730 +0000
+++ include/safe-ctype.h
@@ -121,30 +121,30 @@ extern const unsigned char  _sch_tolower
 
 #include <ctype.h>
 #undef isalpha
-#define isalpha(c) do_not_use_isalpha_with_safe_ctype
+#define isalpha do_not_use_isalpha_with_safe_ctype
 #undef isalnum
-#define isalnum(c) do_not_use_isalnum_with_safe_ctype
+#define isalnum do_not_use_isalnum_with_safe_ctype
 #undef iscntrl
-#define iscntrl(c) do_not_use_iscntrl_with_safe_ctype
+#define iscntrl do_not_use_iscntrl_with_safe_ctype
 #undef isdigit
-#define isdigit(c) do_not_use_isdigit_with_safe_ctype
+#define isdigit do_not_use_isdigit_with_safe_ctype
 #undef isgraph
-#define isgraph(c) do_not_use_isgraph_with_safe_ctype
+#define isgraph do_not_use_isgraph_with_safe_ctype
 #undef islower
-#define islower(c) do_not_use_islower_with_safe_ctype
+#define islower do_not_use_islower_with_safe_ctype
 #undef isprint
-#define isprint(c) do_not_use_isprint_with_safe_ctype
+#define isprint do_not_use_isprint_with_safe_ctype
 #undef ispunct
-#define ispunct(c) do_not_use_ispunct_with_safe_ctype
+#define ispunct do_not_use_ispunct_with_safe_ctype
 #undef isspace
-#define isspace(c) do_not_use_isspace_with_safe_ctype
+#define isspace do_not_use_isspace_with_safe_ctype
 #undef isupper
-#define isupper(c) do_not_use_isupper_with_safe_ctype
+#define isupper do_not_use_isupper_with_safe_ctype
 #undef isxdigit
-#define isxdigit(c) do_not_use_isxdigit_with_safe_ctype
+#define isxdigit do_not_use_isxdigit_with_safe_ctype
 #undef toupper
-#define toupper(c) do_not_use_toupper_with_safe_ctype
+#define toupper do_not_use_toupper_with_safe_ctype
 #undef tolower
-#define tolower(c) do_not_use_tolower_with_safe_ctype
+#define tolower do_not_use_tolower_with_safe_ctype
 
 #endif /* SAFE_CTYPE_H */
