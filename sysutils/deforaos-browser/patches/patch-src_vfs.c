$NetBSD: patch-src_vfs.c,v 1.1 2014/03/21 14:19:31 jperkin Exp $

Need sys/fcntl.h for O_RDONLY on SunOS.

--- src/vfs.c.orig	2013-10-04 23:47:17.000000000 +0000
+++ src/vfs.c
@@ -18,6 +18,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <libgen.h>
+#ifdef __sun
+#include <sys/fcntl.h>
+#endif
 #include "vfs.h"
 
 
