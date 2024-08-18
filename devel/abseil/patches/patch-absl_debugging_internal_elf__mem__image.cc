$NetBSD: patch-absl_debugging_internal_elf__mem__image.cc,v 1.4 2024/08/18 13:52:33 bsiegert Exp $

NetBSD 9 does not have DT_GNU_HASH

--- absl/debugging/internal/elf_mem_image.cc.orig	2024-08-18 13:46:50.153911360 +0000
+++ absl/debugging/internal/elf_mem_image.cc
@@ -225,9 +225,11 @@ void ElfMemImage::Init(const void *base)
       case DT_HASH:
         sysv_hash = reinterpret_cast<uint32_t *>(value);
         break;
+#ifdef DT_GNU_HASH
       case DT_GNU_HASH:
         gnu_hash = reinterpret_cast<uint32_t *>(value);
         break;
+#endif
       case DT_SYMTAB:
         dynsym_ = reinterpret_cast<ElfW(Sym) *>(value);
         break;
