$NetBSD: patch-src_module_spell_spell-custom.c,v 1.1 2023/12/20 12:03:25 nros Exp $

Illumos has endian.h just like Linux

--- src/module/spell/spell-custom.c.orig	2023-12-20 12:48:01.030638913 +0000
+++ src/module/spell/spell-custom.c
@@ -31,7 +31,7 @@
 #include "fcitx-utils/utf8.h"
 #include <sys/stat.h>
 #include <time.h>
-#if defined(__linux__) || defined(__GLIBC__)
+#if defined(__linux__) || defined(__GLIBC__) || defined(__illumos__)
 #include <endian.h>
 #else
 #include <sys/endian.h>
