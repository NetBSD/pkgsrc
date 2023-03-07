$NetBSD: patch-plugin_auth__pam_testing_pam__mariadb__mtr.c,v 1.1 2023/03/07 10:28:02 jperkin Exp $

pam_appl.h must come before pam_modules.h.

--- plugin/auth_pam/testing/pam_mariadb_mtr.c.orig	2022-11-02 12:37:20.000000000 +0000
+++ plugin/auth_pam/testing/pam_mariadb_mtr.c
@@ -10,8 +10,8 @@
 
 #include <stdlib.h>
 #include <string.h>
-#include <security/pam_modules.h>
 #include <security/pam_appl.h>
+#include <security/pam_modules.h>
 
 #define N 3
 
