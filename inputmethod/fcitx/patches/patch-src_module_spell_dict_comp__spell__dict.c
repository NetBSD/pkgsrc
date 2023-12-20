$NetBSD: patch-src_module_spell_dict_comp__spell__dict.c,v 1.1 2023/12/20 12:03:25 nros Exp $

Illumos has endian.h just like Linux

--- src/module/spell/dict/comp_spell_dict.c.orig	2023-12-20 12:44:06.382093226 +0000
+++ src/module/spell/dict/comp_spell_dict.c
@@ -26,7 +26,7 @@
 #include <fcntl.h>
 #include <stdint.h>
 #include <unistd.h>
-#if defined(__linux__) || defined(__GLIBC__)
+#if defined(__linux__) || defined(__GLIBC__) || defined(__illumos__)
 #include <endian.h>
 #else
 #include <sys/endian.h>
