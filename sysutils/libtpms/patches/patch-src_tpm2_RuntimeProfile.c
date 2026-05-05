$NetBSD: patch-src_tpm2_RuntimeProfile.c,v 1.1 2026/05/05 10:20:02 jperkin Exp $

Include strings.h for index().

--- src/tpm2/RuntimeProfile.c.orig	2026-05-05 09:42:37.533232565 +0000
+++ src/tpm2/RuntimeProfile.c
@@ -45,6 +45,7 @@
 #include <stdio.h>
 #include <regex.h>
 #include <limits.h>
+#include <strings.h>
 
 #include "Tpm.h"
 #include "tpm_library_intern.h"
