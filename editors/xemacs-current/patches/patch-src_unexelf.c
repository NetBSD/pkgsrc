$NetBSD: patch-src_unexelf.c,v 1.1 2017/11/15 14:53:27 hauke Exp $

Enhance ELF macros to deal with 32/64 bit arches
Special-case alpha

Was patch-ad

--- src/unexelf.c.orig	2013-08-21 17:43:45.000000000 +0000
+++ src/unexelf.c
@@ -490,10 +490,19 @@ typedef struct {
 
 #ifndef ElfW
 # ifdef __STDC__
-#  define ElfW(type)	Elf32_##type
+#  define ElfBitsW(bits, type) Elf##bits##_##type
 # else
-#  define ElfW(type)	Elf32_/**/type
+#  define ElfBitsW(bits, type) Elf/**/bits/**/_/**/type
 # endif
+# if defined (_LP64) || defined(__alpha__)
+#  define ELFSIZE 64
+# else
+#  define ELFSIZE 32
+# endif
+  /* This macro expands `bits' before invoking ElfBitsW.  */
+# define ElfExpandBitsW(bits, type) ElfBitsW (bits, type)
+# define ElfW(type) ElfExpandBitsW (ELFSIZE, type)
+
 #endif
 
 #ifndef ELF_BSS_SECTION_NAME
@@ -959,7 +968,7 @@ unexec (Extbyte *new_name, Extbyte *old_
       memcpy (NEW_SECTION_H (nn).sh_offset + new_base, src,
 	      NEW_SECTION_H (nn).sh_size);
 
-#ifdef __alpha__
+#if defined(__alpha__) && !defined(__NetBSD__)
       /* Update Alpha COFF symbol table: */
       if (strcmp (old_section_names + OLD_SECTION_H (n).sh_name, ".mdebug")
 	  == 0)
