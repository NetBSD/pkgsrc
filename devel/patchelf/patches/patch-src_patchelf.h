$NetBSD: patch-src_patchelf.h,v 1.1 2026/11/25 10:04:05 pho Exp $

See patches/src_patchelf.cc

--- src/patchelf.h.orig	2026-11-25 09:02:08.242999380 +0000
+++ src/patchelf.h
@@ -107,9 +107,13 @@ private:
 
     [[nodiscard]] std::string getSectionName(const Elf_Shdr & shdr) const;
 
+    using Elf_Shdr_Type = decltype(Elf_Shdr::sh_type);
+
     const Elf_Shdr & findSectionHeader(const SectionName & sectionName) const;
+    const Elf_Shdr & findSectionHeader(Elf_Shdr_Type sectionType) const;
 
     [[nodiscard]] std::optional<std::reference_wrapper<const Elf_Shdr>> tryFindSectionHeader(const SectionName & sectionName) const;
+    [[nodiscard]] std::optional<std::reference_wrapper<const Elf_Shdr>> tryFindSectionHeader(Elf_Shdr_Type sectionType) const;
 
     template<class T> span<T> getSectionSpan(const Elf_Shdr & shdr) const;
     template<class T> span<T> getSectionSpan(const SectionName & sectionName);
@@ -117,6 +121,7 @@ private:
     span<char> getStrTab(const Elf_Shdr & shdr) const;
 
     [[nodiscard]] unsigned int getSectionIndex(const SectionName & sectionName) const;
+    [[nodiscard]] unsigned int getSectionIndex(Elf_Shdr_Type sectionType) const;
 
     std::string & replaceSection(const SectionName & sectionName,
         unsigned int size);
