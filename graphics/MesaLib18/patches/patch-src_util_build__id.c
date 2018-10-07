$NetBSD: patch-src_util_build__id.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

Patch taken from FreeBSD ports graphics/mesa-dri mesa 17.1.0.

# Elf_ doesn't exist, use Elf32_ or Elf64_.

--- src/util/build_id.c.orig	2018-09-07 21:18:07.000000000 +0000
+++ src/util/build_id.c
@@ -35,7 +35,15 @@
 #endif
 
 #ifndef ElfW
-#define ElfW(type) Elf_##type
+# if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#  ifdef __LP64__
+#    define ElfW(type) Elf64_##type
+#  else
+#    define ElfW(type) Elf32_##type
+#  endif /* __LP64__ */
+#  else
+#    define ElfW(type) Elf_##type
+#  endif
 #endif
 
 struct build_id_note {
