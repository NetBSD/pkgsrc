$NetBSD: patch-lib_libpam_openpam__dynamic.c,v 1.1 2016/03/10 12:57:09 tnn Exp $

include limits.h for PATH_MAX

--- lib/libpam/openpam_dynamic.c.orig	2014-09-12 07:48:17.000000000 +0000
+++ lib/libpam/openpam_dynamic.c
@@ -48,6 +48,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#include <limits.h>
 
 #include <security/pam_appl.h>
 
