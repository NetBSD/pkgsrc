$NetBSD: patch-sysincludes.h,v 1.1 2021/01/08 08:47:29 otis Exp $

Include stropts.h when it is present.

--- sysincludes.h.orig	2021-01-03 18:23:22.000000000 +0000
+++ sysincludes.h
@@ -163,6 +163,9 @@
 #if HAVE_SYS_STROPTS_H
 #include <sys/stropts.h>	/* SunOS I_PUSH ... */
 #endif
+#if HAVE_STROPTS_H
+#include <stropts.h>		/* SunOS isastream() */
+#endif
 #if HAVE_REGEX_H
 #include <regex.h>
 #endif
