$NetBSD: patch-src_unexelf.c,v 1.1 2015/02/04 09:19:20 hauke Exp $

--- src/unexelf.c.orig	2015-01-29 15:04:29.000000000 +0000
+++ src/unexelf.c
@@ -494,7 +494,7 @@ typedef struct {
 #  define ElfBitsW(bits, type) Elf/**/bits/**/_/**/type
 # endif
 # ifndef ELFSIZE
-#  ifdef _LP64
+#  if defined(_LP64) || defined(__alpha__)
 #   define ELFSIZE 64
 #  else
 #   define ELFSIZE 32
@@ -970,7 +970,7 @@ unexec (char *new_name, char *old_name, 
       memcpy (NEW_SECTION_H (nn).sh_offset + new_base, src,
 	      NEW_SECTION_H (nn).sh_size);
 
-#ifdef __alpha__
+#if defined(__alpha__) && !defined(__NetBSD__)
       /* Update Alpha COFF symbol table: */
       if (strcmp (old_section_names + OLD_SECTION_H (n).sh_name, ".mdebug")
 	  == 0)
