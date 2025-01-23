$NetBSD: patch-src_wayland-util.h,v 1.1 2025/01/23 17:53:36 riastradh Exp $

Pacify -Wundef / -Werror=undef when compiling C++ programs that use
Wayland header files.
https://gitlab.freedesktop.org/wayland/wayland/-/issues/522

--- src/wayland-util.h.orig	2024-05-30 18:59:51.000000000 +0000
+++ src/wayland-util.h
@@ -48,7 +48,7 @@ extern "C" {
 #endif
 
 /** Deprecated attribute */
-#if __STDC_VERSION__ >= 202311L
+#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
 #define WL_DEPRECATED [[deprecated]]
 #elif defined(__GNUC__) && __GNUC__ >= 4
 #define WL_DEPRECATED __attribute__ ((deprecated))
@@ -70,7 +70,7 @@ extern "C" {
 #define WL_PRINTF(x, y)
 #endif
 
-#if __STDC_VERSION__ >= 202311L
+#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
 #define WL_TYPEOF(expr) typeof(expr)
 #else
 #define WL_TYPEOF(expr) __typeof__(expr)
