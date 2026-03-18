$NetBSD: patch-clara.c,v 1.1 2026/03/18 10:08:44 nia Exp $

Include <alloca.h> on systems that need it, to avoid implicit
function declarations.

--- clara.c.orig	2026-03-18 09:14:16.916083268 +0000
+++ clara.c
@@ -31,6 +31,9 @@ char *version = "0.9.9";
 #include <ctype.h>
 #include <string.h>
 #include <fcntl.h>
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
