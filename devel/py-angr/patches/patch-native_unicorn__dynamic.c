$NetBSD: patch-native_unicorn__dynamic.c,v 1.1 2025/04/17 16:06:22 adam Exp $

Support NetBSD.

--- native/unicorn_dynamic.c.orig	2025-04-17 16:00:17.551663032 +0000
+++ native/unicorn_dynamic.c
@@ -1,6 +1,6 @@
 #include <stdbool.h>
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #include <dlfcn.h>
 #elif defined(_WIN32)
 #include <windows.h>
@@ -13,7 +13,7 @@
 
 bool simunicorn_setup_imports(char *uc_path) {
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__)
 	void *handle = dlopen(uc_path, RTLD_NOW | RTLD_GLOBAL);
 	if (!handle) {
 		return false;
