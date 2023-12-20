$NetBSD: patch-src_module_unicode_charselectdata.c,v 1.1 2023/12/20 12:03:25 nros Exp $

Illumos has endian.h just like Linux

--- src/module/unicode/charselectdata.c.orig	2023-12-20 12:50:04.703947794 +0000
+++ src/module/unicode/charselectdata.c
@@ -11,7 +11,7 @@
 #include <fcitx-utils/utils.h>
 #include <fcitx-config/xdg.h>
 #include <fcitx/fcitx.h>
-#if defined(__linux__) || defined(__GLIBC__)
+#if defined(__linux__) || defined(__GLIBC__) || defined(__illumos__)
 #include <endian.h>
 #else
 #include <sys/endian.h>
