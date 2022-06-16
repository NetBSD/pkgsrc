$NetBSD: patch-libquadmath_strtod_strtod__l.c,v 1.1 2022/06/16 15:43:55 adam Exp $

Fix -Werror=char-subscripts.

https://gcc.gnu.org/bugzilla/show_bug.cgi?id=95178

--- libquadmath/strtod/strtod_l.c.orig	2020-05-07 10:50:02.000000000 +0000
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
