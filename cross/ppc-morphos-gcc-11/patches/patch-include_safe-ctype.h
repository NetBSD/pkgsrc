$NetBSD: patch-include_safe-ctype.h,v 1.1 2025/04/21 22:43:57 js Exp $

Don't define functions from ctype.h to garbage, as it breaks the C++ headers on
Darwin.

--- include/safe-ctype.h.orig	2025-04-21 22:37:25.719755271 +0000
+++ include/safe-ctype.h
@@ -112,39 +112,4 @@ extern const unsigned char  _sch_tolower
 #define TOUPPER(c) _sch_toupper[(c) & 0xff]
 #define TOLOWER(c) _sch_tolower[(c) & 0xff]
 
-/* Prevent the users of safe-ctype.h from accidently using the routines
-   from ctype.h.  Initially, the approach was to produce an error when
-   detecting that ctype.h has been included.  But this was causing
-   trouble as ctype.h might get indirectly included as a result of
-   including another system header (for instance gnulib's stdint.h).
-   So we include ctype.h here and then immediately redefine its macros.  */
-
-#include <ctype.h>
-#undef isalpha
-#define isalpha(c) do_not_use_isalpha_with_safe_ctype
-#undef isalnum
-#define isalnum(c) do_not_use_isalnum_with_safe_ctype
-#undef iscntrl
-#define iscntrl(c) do_not_use_iscntrl_with_safe_ctype
-#undef isdigit
-#define isdigit(c) do_not_use_isdigit_with_safe_ctype
-#undef isgraph
-#define isgraph(c) do_not_use_isgraph_with_safe_ctype
-#undef islower
-#define islower(c) do_not_use_islower_with_safe_ctype
-#undef isprint
-#define isprint(c) do_not_use_isprint_with_safe_ctype
-#undef ispunct
-#define ispunct(c) do_not_use_ispunct_with_safe_ctype
-#undef isspace
-#define isspace(c) do_not_use_isspace_with_safe_ctype
-#undef isupper
-#define isupper(c) do_not_use_isupper_with_safe_ctype
-#undef isxdigit
-#define isxdigit(c) do_not_use_isxdigit_with_safe_ctype
-#undef toupper
-#define toupper(c) do_not_use_toupper_with_safe_ctype
-#undef tolower
-#define tolower(c) do_not_use_tolower_with_safe_ctype
-
 #endif /* SAFE_CTYPE_H */
