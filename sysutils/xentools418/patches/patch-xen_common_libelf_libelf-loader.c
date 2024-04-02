$NetBSD: patch-xen_common_libelf_libelf-loader.c,v 1.1 2024/04/02 22:01:24 bouyer Exp $

Compute total symbol table with the same size as used to build the
symbol table.
This bug only shows up with 32bit guest kernels, and if the end of the
symbol table ends less than 64 bytes from a page boundary. When this
happens the string table is not copied, and the guest sees all symbols with
empty names.

--- xen/common/libelf/libelf-loader.c.orig	2023-11-16 22:44:21.000000000 +0100
+++ xen/common/libelf/libelf-loader.c	2024-04-02 17:12:05.322638541 +0200
@@ -204,10 +204,8 @@
     sz = sizeof(uint32_t);
 
     /* Space for the ELF header and section headers */
-    sz += offsetof(struct elf_sym_header, elf_header.section) +
-          ELF_BSDSYM_SECTIONS * (elf_64bit(elf) ? sizeof(Elf64_Shdr) :
-                                                  sizeof(Elf32_Shdr));
+    sz += sizeof(struct elf_sym_header);
     sz = elf_round_up(elf, sz);
 
     /*
      * No need to search for the symtab section header again, it's handler
