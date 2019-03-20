$NetBSD: patch-config.c,v 1.6 2019/03/20 10:34:10 he Exp $

Fix NetBSD compilation.

--- config.c.orig	2016-12-02 13:12:33.000000000 +0000
+++ config.c
@@ -23,7 +23,9 @@
 #include <wctype.h>
 #include <fnmatch.h>
 #include <sys/mman.h>
-#include <libgen.h>
+#ifndef _LIBGEN_H_
+#  include <libgen.h>
+#endif
 
 #if !defined(PATH_MAX) && defined(__FreeBSD__)
 #include <sys/param.h>
