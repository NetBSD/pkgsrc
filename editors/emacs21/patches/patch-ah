$NetBSD: patch-ah,v 1.2 2016/11/26 04:22:40 dholland Exp $

- Set ELFSIZE correctly (from exec_elf.h)
- not sure what the rest is about (XXX)

--- src/unexelf.c.orig	2002-10-15 14:21:44.000000000 +0000
+++ src/unexelf.c
@@ -499,12 +499,14 @@ typedef struct {
 /*
  * NetBSD does not have normal-looking user-land ELF support.
  */
+# include <sys/exec_elf.h>
+# ifndef ELFSIZE
 # if defined __alpha__ || defined __sparc_v9__
 #  define ELFSIZE	64
 # else
 #  define ELFSIZE	32
 # endif
-# include <sys/exec_elf.h>
+# endif
 
 # ifndef PT_LOAD
 #  define PT_LOAD	Elf_pt_load
@@ -971,8 +973,13 @@ unexec (new_name, old_name, data_start, 
 	}
       else
 	{
-	  /* Any section that was original placed AFTER the bss
-	     section should now be off by NEW_DATA2_SIZE. */
+	  /* Any section that was originally placed after the .bss
+	     section should now be off by NEW_DATA2_SIZE.  If a
+	     section overlaps the .bss section, consider it to be
+	     placed after the .bss section.  Overlap can occur if the
+	     section just before .bss has less-strict alignment; this
+	     was observed between .symtab and .bss on Solaris 2.5.1
+	     (sparc) with GCC snapshot 960602.  */
 #ifdef SOLARIS_POWERPC
 	  /* On PPC Reference Platform running Solaris 2.5.1
 	     the plt section is also of type NOBI like the bss section.
@@ -986,9 +993,8 @@ unexec (new_name, old_name, data_start, 
 	      >= OLD_SECTION_H (old_bss_index-1).sh_offset)
 	    NEW_SECTION_H (nn).sh_offset += new_data2_size;
 #else
-	  if (round_up (NEW_SECTION_H (nn).sh_offset,
-			OLD_SECTION_H (old_bss_index).sh_addralign)
-	      >= new_data2_offset)
+	  if (NEW_SECTION_H (nn).sh_offset + NEW_SECTION_H (nn).sh_size
+	      > new_data2_offset)
 	    NEW_SECTION_H (nn).sh_offset += new_data2_size;
 #endif
 	  /* Any section that was originally placed after the section
