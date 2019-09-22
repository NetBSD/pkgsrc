$NetBSD: patch-cfgpath.h,v 1.1 2019/09/22 12:10:45 nia Exp $

Support NetBSD.

--- ./cfgpath.h.orig	2015-10-21 02:55:38.000000000 -0700
+++ ./cfgpath.h	2016-01-23 22:09:05.000000000 -0800
@@ -39,7 +39,7 @@
 #define mkdir _mkdir
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #include <string.h>
 #include <stdlib.h>
 #include <sys/stat.h>
@@ -88,7 +88,7 @@
  */
 static inline void get_user_config_file(char *out, unsigned int maxlen, const char *appname)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 	const char *out_orig = out;
 	char *home = getenv("XDG_CONFIG_HOME");
 	unsigned int config_len = 0;
@@ -194,7 +194,7 @@
  */
 static inline void get_user_config_folder(char *out, unsigned int maxlen, const char *appname)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 	const char *out_orig = out;
 	char *home = getenv("XDG_CONFIG_HOME");
 	unsigned int config_len = 0;
@@ -311,7 +311,7 @@
  */
 static inline void get_user_data_folder(char *out, unsigned int maxlen, const char *appname)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 	const char *out_orig = out;
 	char *home = getenv("XDG_DATA_HOME");
 	unsigned int config_len = 0;
@@ -396,7 +396,7 @@
  */
 static inline void get_user_cache_folder(char *out, unsigned int maxlen, const char *appname)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 	const char *out_orig = out;
 	char *home = getenv("XDG_CACHE_HOME");
 	unsigned int config_len = 0;
