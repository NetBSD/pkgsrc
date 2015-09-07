$NetBSD: patch-src_common_compat__getopt.h,v 1.3 2015/09/07 19:59:42 gdt Exp $

NetBSD has getopt_long but not getopt_long_only.  Replacing
getopt_long causes a type conflict with the built-in implementation.
The replacement is unnecesssary because getopt_long_only is not
actually used.

Reported upstream:
http://article.gmane.org/gmane.comp.encryption.opensc.user/5931

The following is the original mail archive URL, but it currently
yields a '404 not found' error:
https://www.opensc-project.org/pipermail/opensc-devel/2012-November/018668.html

--- src/common/compat_getopt.h.orig	2015-05-16 20:30:24.000000000 +0000
+++ src/common/compat_getopt.h
@@ -30,7 +30,7 @@
 #include "config.h"
 #endif
 
-#if defined(HAVE_GETOPT_H) && defined(HAVE_GETOPT_LONG) && defined(HAVE_GETOPT_LONG_ONLY)
+#if defined(HAVE_GETOPT_H) && defined(HAVE_GETOPT_LONG)
 #include <getopt.h>
 #else
 
@@ -43,7 +43,6 @@ extern "C" {
 
 #define getopt my_getopt
 #define getopt_long my_getopt_long
-#define getopt_long_only my_getopt_long_only
 #define _getopt_internal _my_getopt_internal
 #define opterr my_opterr
 #define optind my_optind
@@ -86,6 +85,6 @@ extern int _my_getopt_internal(int argc,
 }
 #endif
 
-#endif /* HAVE_GETOPT_H && HAVE_GETOPT_LONG && HAVE_GETOPT_LONG_ONLY */
+#endif /* HAVE_GETOPT_H && HAVE_GETOPT_LONG */
 
 #endif /* MY_GETOPT_H_INCLUDED */
