$NetBSD: patch-src_app.c,v 1.1 2026/10/13 08:36:47 drixter Exp $

AC_HEADER_STDC is obsolete, all pkgsrc supported platforms should
likely have them.

--- src/app.c.orig	2005-09-20 05:55:34.000000000 +0000
+++ src/app.c
@@ -37,10 +37,8 @@
 #include "config.h"
 #endif
 
-#ifdef STDC_HEADERS
 #include <stdio.h>
 #include <stdlib.h>
-#endif
 
 #ifdef HAVE_STRING_H
 #include <string.h>
@@ -62,6 +60,9 @@
 
 #ifdef HAVE_SECURITY_PAM_MISC_H
 #include <security/pam_misc.h>
+#else
+#include <security/openpam.h>
+#define	misc_conv	openpam_ttyconv
 #endif
 
 #ifdef HAVE_PAM_PAM_MISC_H
