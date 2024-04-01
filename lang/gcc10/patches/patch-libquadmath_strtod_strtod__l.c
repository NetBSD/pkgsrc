$NetBSD: patch-libquadmath_strtod_strtod__l.c,v 1.2 2024/04/01 14:33:58 js Exp $

Fix -Werror=char-subscripts.

https://gcc.gnu.org/bugzilla/show_bug.cgi?id=95178

Fix _MAX and _MIN being defined on QNX and breaking the concatenation.

--- libquadmath/strtod/strtod_l.c.orig	2023-07-07 07:08:21.000000000 +0000
+++ libquadmath/strtod/strtod_l.c
@@ -57,10 +57,10 @@
 # define STRING_TYPE char
 # define CHAR_TYPE char
 # define L_(Ch) Ch
-# define ISSPACE(Ch) isspace (Ch)
-# define ISDIGIT(Ch) isdigit (Ch)
-# define ISXDIGIT(Ch) isxdigit (Ch)
-# define TOLOWER(Ch) tolower (Ch)
+# define ISSPACE(Ch) isspace ((unsigned char) Ch)
+# define ISDIGIT(Ch) isdigit ((unsigned char) Ch)
+# define ISXDIGIT(Ch) isxdigit ((unsigned char) Ch)
+# define TOLOWER(Ch) tolower ((unsigned char) Ch)
 # define TOLOWER_C(Ch) \
   ({__typeof(Ch) __tlc = (Ch); \
     (__tlc >= 'A' && __tlc <= 'Z') ? __tlc - 'A' + 'a' : __tlc; })
@@ -89,6 +89,13 @@ __quadmath_strncasecmp_c (const char *s1
 #endif
 
 
+#ifdef _MAX
+#undef _MAX
+#endif
+#ifdef _MIN
+#undef _MIN
+#endif
+
 /* Constants we need from float.h; select the set for the FLOAT precision.  */
 #define MANT_DIG	PASTE(FLT,_MANT_DIG)
 #define	DIG		PASTE(FLT,_DIG)
