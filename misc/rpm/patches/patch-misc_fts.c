$NetBSD: patch-misc_fts.c,v 1.1 2013/09/13 12:41:32 ryoon Exp $

* Definitions for NetBSD.

--- misc/fts.c.orig	2012-11-18 08:21:06.000000000 +0000
+++ misc/fts.c
@@ -61,6 +61,11 @@ static char sccsid[] = "@(#)fts.c	8.6 (B
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
