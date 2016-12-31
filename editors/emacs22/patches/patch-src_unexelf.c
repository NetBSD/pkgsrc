$NetBSD: patch-src_unexelf.c,v 1.1 2016/12/31 06:11:21 dholland Exp $

- Set ELFSIZE correctly (from exec_elf.h)

--- src/unexelf.c~	2008-01-08 04:29:48.000000000 +0000
+++ src/unexelf.c
@@ -489,12 +489,14 @@ typedef struct {
 /*
  * NetBSD does not have normal-looking user-land ELF support.
  */
+# include <sys/exec_elf.h>
 # if defined __alpha__ || defined __sparc_v9__
+# ifndef ELFSIZE
 #  define ELFSIZE	64
 # else
 #  define ELFSIZE	32
 # endif
-# include <sys/exec_elf.h>
+# endif
 
 # ifndef PT_LOAD
 #  define PT_LOAD	Elf_pt_load
