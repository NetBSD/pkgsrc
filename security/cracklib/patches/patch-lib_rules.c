$NetBSD: patch-lib_rules.c,v 1.1 2020/11/22 11:36:32 nia Exp $

Argument to ctype functions must be unsigned char.

--- lib/rules.c.orig	2019-02-14 01:54:41.000000000 +0000
+++ lib/rules.c
@@ -14,8 +14,8 @@ static const char vers_id[] = "rules.c :
 #include "crack.h"
 #include "packer.h"
 
-#define CRACK_TOLOWER(a)        (isupper(a)?tolower(a):(a))
-#define CRACK_TOUPPER(a)        (islower(a)?toupper(a):(a))
+#define CRACK_TOLOWER(a)        (isupper((unsigned char)a)?tolower((unsigned char)a):(a))
+#define CRACK_TOUPPER(a)        (islower((unsigned char)a)?toupper((unsigned char)a):(a))
 #define STRCMP(a,b)             strcmp((a),(b))
 
 #if 0
