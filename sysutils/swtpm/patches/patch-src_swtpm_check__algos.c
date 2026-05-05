$NetBSD: patch-src_swtpm_check__algos.c,v 1.1 2026/05/05 10:21:46 jperkin Exp $

Include strings.h for index().

--- src/swtpm/check_algos.c.orig	2026-05-05 08:19:35.380080466 +0000
+++ src/swtpm/check_algos.c
@@ -41,6 +41,7 @@
 #include <errno.h>
 #include <stdio.h>
 #include <string.h>
+#include <strings.h>
 
 #include "check_algos.h"
 #include "utils.h"
