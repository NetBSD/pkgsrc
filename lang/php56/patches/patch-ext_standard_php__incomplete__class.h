$NetBSD: patch-ext_standard_php__incomplete__class.h,v 1.1 2026/10/27 15:30:49 taca Exp $

https://raw.githubusercontent.com/Anton-Barinov/php2shell-patches/refs/heads/main/patches/php-5.6-enhanced-universal.patch

--- ext/standard/php_incomplete_class.h.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/standard/php_incomplete_class.h
@@ -52,6 +52,9 @@
 
 #define INCOMPLETE_CLASS "__PHP_Incomplete_Class"
 #define MAGIC_MEMBER "__PHP_Incomplete_Class_Name"
+/* Set by php_var_unserialize() while BG(incomplete_classes_only): the raw
+ * payload of a C: value, written back unchanged by php_var_serialize() */
+#define MAGIC_MEMBER_SERIALIZED "__PHP_Incomplete_Class_Serialized"
 
 #ifdef __cplusplus
 extern "C" {
