$NetBSD: patch-src_library_grDevices_src_devPS.c,v 1.1 2026/02/16 23:44:02 mef Exp $

devPS.c: In function 'PDF_endfile':
devPS.c:8173:9: error: implicit declaration of function 'unlink' [-Wimplicit-function-declaration]
 8173 |         unlink(pd->filename);
      |         ^~~~~~
gmake[5]: *** [../../../../etc/Makeconf:202: devPS.o] Error 1

--- src/library/grDevices/src/devPS.c.orig	2025-03-14 08:02:05.000000000 +0900
+++ src/library/grDevices/src/devPS.c	2026-01-03 19:41:50.895118374 +0900
@@ -29,6 +29,7 @@
 #include <ctype.h>
 #include <limits.h> /* required for MB_LEN_MAX */
 #include <string.h>
+#include <unistd.h> /* for unlink */
 
 #include <wchar.h>
 #include <wctype.h>
