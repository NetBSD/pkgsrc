$NetBSD: patch-lib_libpam_openpam__configure.c,v 1.3 2016/03/10 12:57:09 tnn Exp $

include limits.h for PATH_MAX

--- lib/libpam/openpam_configure.c.orig	2014-09-12 07:48:21.000000000 +0000
+++ lib/libpam/openpam_configure.c
@@ -45,6 +45,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <limits.h>
 
 #include <security/pam_appl.h>
 
