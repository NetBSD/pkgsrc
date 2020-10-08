$NetBSD: patch-config.c,v 1.7 2020/10/08 07:50:51 wiz Exp $

Fix NetBSD compilation.

--- config.c.orig	2020-07-10 08:22:39.000000000 +0000
+++ config.c
@@ -19,7 +19,13 @@
 #include <wctype.h>
 #include <fnmatch.h>
 #include <sys/mman.h>
-#include <libgen.h>
+#ifndef _LIBGEN_H_
+#  include <libgen.h>
+#endif
+
+#ifndef secure_getenv
+#define secure_getenv getenv
+#endif
 
 #if !defined(PATH_MAX) && defined(__FreeBSD__)
 #include <sys/param.h>
