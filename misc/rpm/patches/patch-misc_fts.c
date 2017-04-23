$NetBSD: patch-misc_fts.c,v 1.3 2017/04/23 08:18:15 adam Exp $

* Detect dirfd(3) and setprogname(3) in configure script.

--- misc/fts.c.orig	2016-11-30 07:03:00.000000000 +0000
+++ misc/fts.c
@@ -32,7 +32,7 @@ static char sccsid[] = "@(#)fts.c	8.6 (B
 #endif /* LIBC_SCCS and not lint */
 
 /* Conditional to set up proper fstat64 implementation */
-#if defined(hpux) || defined(sun)
+#if defined(hpux) || defined(sun) || defined(__NetBSD__)
 #   define FTS_FSTAT64(_fd, _sbp)   fstat((_fd), (_sbp))
 #else
 #   define FTS_FSTAT64(_fd, _sbp)   fstat64((_fd), (_sbp))
@@ -59,11 +59,18 @@ static char sccsid[] = "@(#)fts.c	8.6 (B
 #endif
 #if defined(sun)
 #   define __errno_location()	(&errno)
+# if defined(HAVE_DIRFD)
 #   define dirfd(dirp)		-1
+# endif
 #endif
 #if defined(__APPLE__)
 #   define __errno_location()	(__error())
 #endif
+#if defined(__NetBSD__)
+#   define __errno_location()  (&errno)
+#   define stat64              stat
+#   define __fxstat64(_stat_ver, _fd, _sbp)    fstat((_fd), (_sbp))
+#endif
 
 #include "system.h"
 #include <stdlib.h>
