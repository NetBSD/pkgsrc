$NetBSD: patch-bfd_elfcode.h,v 1.1 2021/01/07 09:47:47 fcambus Exp $

Upstream fix for CVE-2020-35448.

	PR 26574
	* elfcode.h (elf_object_p): Sanity check section header offset.

--- bfd/elfcode.h.orig	2020-09-03 14:59:37.000000000 +0000
+++ bfd/elfcode.h
@@ -568,7 +568,7 @@ elf_object_p (bfd *abfd)
 
   /* If this is a relocatable file and there is no section header
      table, then we're hosed.  */
-  if (i_ehdrp->e_shoff == 0 && i_ehdrp->e_type == ET_REL)
+  if (i_ehdrp->e_shoff < sizeof (x_ehdr) && i_ehdrp->e_type == ET_REL)
     goto got_wrong_format_error;
 
   /* As a simple sanity check, verify that what BFD thinks is the
@@ -578,7 +578,7 @@ elf_object_p (bfd *abfd)
     goto got_wrong_format_error;
 
   /* Further sanity check.  */
-  if (i_ehdrp->e_shoff == 0 && i_ehdrp->e_shnum != 0)
+  if (i_ehdrp->e_shoff < sizeof (x_ehdr) && i_ehdrp->e_shnum != 0)
     goto got_wrong_format_error;
 
   ebd = get_elf_backend_data (abfd);
@@ -615,7 +615,7 @@ elf_object_p (bfd *abfd)
       && ebd->elf_osabi != ELFOSABI_NONE)
     goto got_wrong_format_error;
 
-  if (i_ehdrp->e_shoff != 0)
+  if (i_ehdrp->e_shoff >= sizeof (x_ehdr))
     {
       file_ptr where = (file_ptr) i_ehdrp->e_shoff;
 
@@ -807,7 +807,7 @@ elf_object_p (bfd *abfd)
 	}
     }
 
-  if (i_ehdrp->e_shstrndx != 0 && i_ehdrp->e_shoff != 0)
+  if (i_ehdrp->e_shstrndx != 0 && i_ehdrp->e_shoff >= sizeof (x_ehdr))
     {
       unsigned int num_sec;
 
