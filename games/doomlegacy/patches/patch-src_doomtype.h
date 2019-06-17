$NetBSD: patch-src_doomtype.h,v 1.1 2019/06/17 13:53:22 micha Exp $

Always use limits.h for pkgsrc.

--- src/doomtype.h.orig	2018-07-16 09:17:06.000000000 +0000
+++ src/doomtype.h
@@ -165,53 +165,37 @@ int strlwr(char *n);
 #endif
 
 
-// Predefined with some OS.
-#ifdef __WIN32__
+// For pkgsrc: Only POSIX conformant OS are supported
 #include <limits.h>
-#elif defined( MACOS_DI ) || defined( __MACH__ ) || defined( FREEBSD )
-#include <limits.h>
-#else
-// Linux GNU, which also includes limits.h
-// obsolete header file
-#include <values.h>
-//#include <limits.h>
-#endif
 
-// [WDJ] This is very dangerous considering 32 bit and 64 bit systems,
-// should use stdint.h values instead.
-// These are obsolete defines from values.h.
 #ifndef MAXCHAR
 // unused
-#define MAXCHAR   ((char)0x7f)
+#define MAXCHAR   CHAR_MAX
 #endif
 
 #ifndef MAXSHORT
-// defined in values.h
 // used in r_segs.c
-#define MAXSHORT  ((short)0x7fff)
+#define MAXSHORT  SHRT_MAX
 #endif
 
 #ifndef MAXINT
-// defined in values.h
 // used in many places
-#define MAXINT    ((int)0x7fffffff)
+#define MAXINT    INT_MAX
 #endif
 
 #ifndef MINCHAR
 // unused
-#define MINCHAR   ((char)0x80)
+#define MINCHAR   CHAR_MIN
 #endif
 
 #ifndef MINSHORT
-// defined in values.h
 // unused
-#define MINSHORT  ((short)0x8000)
+#define MINSHORT  SHRT_MIN
 #endif
 
 #ifndef MININT
-// defined in values.h
 // used in many places
-#define MININT    ((int)0x80000000)
+#define MININT    INT_MIN
 #endif
 
 // Sound effect id type.
