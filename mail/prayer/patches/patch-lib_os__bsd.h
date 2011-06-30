$NetBSD: patch-lib_os__bsd.h,v 1.1 2011/06/30 01:17:38 schnoebe Exp $

--- lib/os_bsd.h.orig	2010-07-08 09:34:25.000000000 +0000
+++ lib/os_bsd.h
@@ -11,6 +11,6 @@
 #ifdef __GLIBC__
 #include <sys/file.h>
 #include <pty.h>
-#else
+#elif !defined(__NetBSD__)
 #include <libutil.h>
 #endif
