$NetBSD: patch-libebutils_puts__eucjp.c,v 1.1 2026/06/18 14:36:49 nia Exp $

Older NetBSD and SunOS have the traditional iconv prototype with a const
char * argument, while other operating systems are using a char *
argument due to historical accidents in the POSIX standard.

Newer C compiler versions (e.g. GCC 14) have strict enforcement of
pointer type compatibility. Thus a const char * cannot be converted
easily back into a non-const char *. So we need to match the prototype
of the iconv function carefully.

--- libebutils/puts_eucjp.c.orig	2026-06-18 14:30:09.401447683 +0000
+++ libebutils/puts_eucjp.c
@@ -46,6 +46,13 @@
 #include <langinfo.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#endif
+#endif
+
 /*
  * Convert `string' from EUC-JP to the current locale encoding, and
  * then write it to `stream'.
@@ -59,7 +66,11 @@ fputs_eucjp_to_locale(const char *string, FILE *stream
     char *buffer = NULL;
     size_t buffer_size;
     iconv_t cd = (iconv_t)-1;
+#if (defined(__sun) || defined(__NetBSD__)) && !defined(NETBSD_POSIX_ICONV) && !defined(_LIBICONV_VERSION)
     const char *in_p;
+#else
+    char *in_p;
+#endif
     char *out_p;
     size_t in_left;
     size_t out_left;
