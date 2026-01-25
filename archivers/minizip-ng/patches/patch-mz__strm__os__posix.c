$NetBSD: patch-mz__strm__os__posix.c,v 1.1 2026/01/25 08:32:53 adam Exp $

Fix build on BSD.
https://github.com/zlib-ng/minizip-ng/issues/941

--- mz_strm_os_posix.c.orig	2026-01-25 08:28:26.034235124 +0000
+++ mz_strm_os_posix.c
@@ -21,6 +21,9 @@
 #include <errno.h>
 #include <unistd.h>  // open, close, ...
 #include <fcntl.h>   // O_NOFOLLOW, ...
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+#include <sys/stat.h>
+#endif
 
 /***************************************************************************/
 
