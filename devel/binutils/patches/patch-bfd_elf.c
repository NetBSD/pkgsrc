$NetBSD: patch-bfd_elf.c,v 1.1 2021/01/07 09:47:47 fcambus Exp $

Upstream fix for CVE-2020-35448.

	PR 26574
	* elf.c (_bfd_elf_slurp_secondary_reloc_section): Sanity check
	sh_entsize.

--- bfd/elf.c.orig	2020-09-03 14:59:14.000000000 +0000
+++ bfd/elf.c
@@ -12527,7 +12527,9 @@ _bfd_elf_slurp_secondary_reloc_section (
       Elf_Internal_Shdr * hdr = & elf_section_data (relsec)->this_hdr;
 
       if (hdr->sh_type == SHT_SECONDARY_RELOC
-	  && hdr->sh_info == (unsigned) elf_section_data (sec)->this_idx)
+	  && hdr->sh_info == (unsigned) elf_section_data (sec)->this_idx
+	  && (hdr->sh_entsize == ebd->s->sizeof_rel
+	      || hdr->sh_entsize == ebd->s->sizeof_rela))
 	{
 	  bfd_byte * native_relocs;
 	  bfd_byte * native_reloc;
