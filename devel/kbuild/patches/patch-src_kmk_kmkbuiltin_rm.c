$NetBSD: patch-src_kmk_kmkbuiltin_rm.c,v 1.1 2016/07/08 09:42:54 kamil Exp $

Add NetBSD support.

--- src/kmk/kmkbuiltin/rm.c.orig	2015-06-21 21:21:29.000000000 +0000
+++ src/kmk/kmkbuiltin/rm.c
@@ -66,6 +66,9 @@ static char sccsid[] = "@(#)rm.c	8.5 (Be
 #ifdef __HAIKU__
 # include "haikufakes.h"
 #endif
+#ifdef __NetBSD__
+# include "strtofflags.c"
+#endif
 #ifdef KBUILD_OS_WINDOWS
 # ifdef _MSC_VER
 #  include "mscfakes.h"
