$NetBSD: patch-bfd_elf32-ppc.c,v 1.1 2025/04/28 20:45:02 js Exp $

Fix baserel.

Patch from Harry Sintonen.

--- bfd/elf32-ppc.c.orig	2025-04-28 20:39:15.782248003 +0000
+++ bfd/elf32-ppc.c
@@ -701,19 +701,19 @@ static reloc_howto_type ppc_elf_howto_ra
 
 #ifdef MORPHOS_TARGET
   /* 32-bit relocation relative to _SDA_BASE_ */
-  HOW (R_PPC_MORPHOS_DREL, 2, 32, 0, 0, false, bitfield,
+  HOW (R_PPC_MORPHOS_DREL, 4, 32, 0, 0, false, bitfield,
        bfd_elf_generic_reloc),
 
   /* Lower 16 bits of a relocation relative to _SDA_BASE */
-  HOW (R_PPC_MORPHOS_DREL_LO, 1, 16, 0xffff, 0, false, dont,
+  HOW (R_PPC_MORPHOS_DREL_LO, 2, 16, 0xffff, 0, false, dont,
        bfd_elf_generic_reloc),
 
   /* Upper 16 bits of a relocation relative to _SDA_BASE */
-  HOW (R_PPC_MORPHOS_DREL_HI, 1, 16, 0xffff, 16, false, dont,
+  HOW (R_PPC_MORPHOS_DREL_HI, 2, 16, 0xffff, 16, false, dont,
        bfd_elf_generic_reloc),
 
   /* Upper 16 bits of a relocation relative to _SDA_BASE */
-  HOW (R_PPC_MORPHOS_DREL_HA, 1, 16, 0xffff, 16, false, dont,
+  HOW (R_PPC_MORPHOS_DREL_HA, 2, 16, 0xffff, 16, false, dont,
        bfd_elf_generic_reloc),
 #endif
 
