$NetBSD: patch-src_swtpm_common.c,v 1.1 2026/05/05 10:21:46 jperkin Exp $

Include strings.h for index().

--- src/swtpm/common.c.orig	2026-05-05 08:19:23.642111097 +0000
+++ src/swtpm/common.c
@@ -40,6 +40,7 @@
 #define _GNU_SOURCE
 #include <stdio.h>
 #include <string.h>
+#include <strings.h>
 #include <errno.h>
 #include <unistd.h>
 #include <sys/types.h>
