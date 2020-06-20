$NetBSD: patch-arch_mips_config.mk,v 1.1 2020/06/20 17:46:28 thorpej Exp $

Use the standard little-endian MIPS ELF target / emulation as supplied
by cross-mipsel-none-elf-binutils.

--- arch/mips/config.mk.orig	2020-06-20 13:56:22.000000000 +0000
+++ arch/mips/config.mk	2020-06-20 14:12:40.000000000 +0000
@@ -13,10 +13,10 @@ PLATFORM_LDFLAGS	+= -EB
 endif
 
 ifdef CONFIG_SYS_LITTLE_ENDIAN
-32bit-emul		:= elf32ltsmip
-64bit-emul		:= elf64ltsmip
-32bit-bfd		:= elf32-tradlittlemips
-64bit-bfd		:= elf64-tradlittlemips
+32bit-emul		:= elf32elmip
+64bit-emul		:= elf64elmip
+32bit-bfd		:= elf32-littlemips
+64bit-bfd		:= elf64-littlemips
 PLATFORM_CPPFLAGS	+= -EL
 PLATFORM_LDFLAGS	+= -EL
 endif
