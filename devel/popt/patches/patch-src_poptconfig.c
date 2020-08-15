$NetBSD: patch-src_poptconfig.c,v 1.1 2020/08/15 01:02:42 tnn Exp $

date: 2009-04-22 17:25:05 +0200;  author: tnn;  state: Exp;  lines: +14 -11;
patch-aa: fix devel/popt build on NetBSD-current (>=5.99.11) which
          has glob_pattern_p(3) in libc.
Reported in PR pkg/41265.

--- src/poptconfig.c.orig	2020-04-16 10:32:54.000000000 +0000
+++ src/poptconfig.c
@@ -21,7 +21,10 @@
 #if defined(HAVE_GLOB_H)
 #include <glob.h>
 
-#if !defined(__GLIBC__)
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+#if !defined(__GLIBC__) && (!defined(__NetBSD__) || __NetBSD_Version__ < 599001100)
 /* Return nonzero if PATTERN contains any metacharacters.
    Metacharacters can be quoted with backslashes if QUOTE is nonzero.  */
 static int
