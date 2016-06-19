$NetBSD: patch-ld_emultempl_sh64elf.em,v 1.1 2016/06/19 16:18:28 wiz Exp $

--- ld/emultempl/sh64elf.em.orig	2016-04-04 16:42:51.033302791 +0000
+++ ld/emultempl/sh64elf.em
@@ -559,3 +559,4 @@ sh64_elf_${EMULATION_NAME}_after_allocat
   cranges->size = crangesp - cranges->contents;
   cranges->rawsize = cranges->size;
 }
+EOF
