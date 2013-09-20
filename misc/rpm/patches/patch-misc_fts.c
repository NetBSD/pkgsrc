$NetBSD: patch-misc_fts.c,v 1.2 2013/09/20 17:26:14 ryoon Exp $

* Detect dirfd(3) and setprogname(3) in configure script.

--- misc/fts.c.orig	2012-11-18 08:21:06.000000000 +0000
+++ misc/fts.c
@@ -52,7 +52,9 @@ static char sccsid[] = "@(#)fts.c	8.6 (B
 #endif
 #if defined(sun)
 #   define __errno_location()	(&errno)
+# if defined(HAVE_DIRFD)
 #   define dirfd(dirp)		-1
+# endif
 #   define _STAT_VER		0
 #   define __fxstat64(_stat_ver, _fd, _sbp)	fstat((_fd), (_sbp))
 #endif
@@ -61,6 +63,11 @@ static char sccsid[] = "@(#)fts.c	8.6 (B
 #   define _STAT_VER		0
 #   define __fxstat64(_stat_ver, _fd, _sbp) fstat64((_fd), (_sbp))
 #endif
+#if defined(__NetBSD__)
+#   define __errno_location() 	(&errno)
+#   define stat64		stat
+#   define __fxstat64(_stat_ver, _fd, _sbp)	fstat((_fd), (_sbp))
+#endif
 #include "system.h"
 #include <stdlib.h>
 #include <string.h>
