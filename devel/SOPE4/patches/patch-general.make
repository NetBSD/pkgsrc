$NetBSD: patch-general.make,v 1.1 2020/08/11 18:48:57 joerg Exp $

Don't include command line in output.

--- general.make.orig	2020-08-10 11:54:58.508538683 +0000
+++ general.make
@@ -23,5 +23,5 @@ endif
 # information plus the compiler flags used; that can
 # be afterwards read with:
 # readelf -p .GCC.command.line /path/to/elf_file
-ADDITIONAL_OBJCFLAGS += -g $(call cc-option,-frecord-gcc-switches)
+ADDITIONAL_OBJCFLAGS += -g
 
