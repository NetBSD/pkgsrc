$NetBSD: patch-contrib_dlz_modules_wildcard_dlz__wildcard__dynamic.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- contrib/dlz/modules/wildcard/dlz_wildcard_dynamic.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ contrib/dlz/modules/wildcard/dlz_wildcard_dynamic.c
@@ -59,6 +59,8 @@
 #include <dlz_list.h>
 #include <dlz_minimal.h>
 
+#include <ctype.h>
+
 #define DE_CONST(konst, var)           \
 	do {                           \
 		union {                \
