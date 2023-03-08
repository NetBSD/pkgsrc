$NetBSD: patch-Source_cmSystemTools.cxx,v 1.1 2023/03/08 04:24:03 charlotte Exp $

DragonFly also benefits from _XOPEN_SOURCE >= 700 (it grants access to
gettimeofday() at the very least)

--- Source/cmSystemTools.cxx.orig	2023-03-08 03:53:53.090719000 -0800
+++ Source/cmSystemTools.cxx	2023-03-08 03:54:20.059507000 -0800
@@ -6,7 +6,7 @@
 // NOLINTNEXTLINE(bugprone-reserved-identifier)
 #  define _POSIX_C_SOURCE 200809L
 #endif
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__QNX__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__QNX__)
 // For isascii
 // NOLINTNEXTLINE(bugprone-reserved-identifier)
 #  define _XOPEN_SOURCE 700
