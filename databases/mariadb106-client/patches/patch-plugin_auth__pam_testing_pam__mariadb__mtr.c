$NetBSD: patch-plugin_auth__pam_testing_pam__mariadb__mtr.c,v 1.1 2022/04/14 10:55:33 tm Exp $

Re-order include for pam_modules dependency (pam_appl.h) especially on SunOS.

--- plugin/auth_pam/testing/pam_mariadb_mtr.c.orig	2021-11-05 20:03:30.000000000 +0000
+++ plugin/auth_pam/testing/pam_mariadb_mtr.c
@@ -10,8 +10,8 @@
 
 #include <stdlib.h>
 #include <string.h>
-#include <security/pam_modules.h>
 #include <security/pam_appl.h>
+#include <security/pam_modules.h>
 
 #define N 3
 
