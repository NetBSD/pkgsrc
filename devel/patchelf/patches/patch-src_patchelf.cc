$NetBSD: patch-src_patchelf.cc,v 1.2 2026/11/25 10:04:05 pho Exp $

Fix for SunOS: There are no sections ".gnu.version_r", ".gnu.version_d", or
".gnu.version" on this platform. The corresponding sections are
".SUNW_version", ".SUNW_version", and ".SUNW_versym" respectively. But
since the first two sections have the same name, we have to disambiguate
them with a section type.

TODO: Test this more thoroughly and then send a pull request to the
upstream.

--- src/patchelf.cc.orig	1970-01-01 00:00:01.000000000 +0000
+++ src/patchelf.cc
@@ -620,6 +620,16 @@ const Elf_Shdr & ElfFile<ElfFileParamNam
     return *shdr;
 }
 
+template<ElfFileParams>
+const Elf_Shdr & ElfFile<ElfFileParamNames>::findSectionHeader(Elf_Shdr_Type sectionType) const
+{
+    auto shdr = tryFindSectionHeader(sectionType);
+    if (!shdr) {
+        std::string extraMsg;
+        error(fmt("cannot find section with type " + sectionType));
+    }
+    return *shdr;
+}
 
 template<ElfFileParams>
 std::optional<std::reference_wrapper<const Elf_Shdr>> ElfFile<ElfFileParamNames>::tryFindSectionHeader(const SectionName & sectionName) const
@@ -631,6 +641,15 @@ std::optional<std::reference_wrapper<con
 }
 
 template<ElfFileParams>
+std::optional<std::reference_wrapper<const Elf_Shdr>> ElfFile<ElfFileParamNames>::tryFindSectionHeader(Elf_Shdr_Type sectionType) const
+{
+    auto i = getSectionIndex(sectionType);
+    if (i)
+        return shdrs.at(i);
+    return {};
+}
+
+template<ElfFileParams>
 template<class T>
 span<T> ElfFile<ElfFileParamNames>::getSectionSpan(const Elf_Shdr & shdr) const
 {
@@ -674,6 +693,14 @@ unsigned int ElfFile<ElfFileParamNames>:
 }
 
 template<ElfFileParams>
+unsigned int ElfFile<ElfFileParamNames>::getSectionIndex(Elf_Shdr_Type sectionType) const
+{
+    for (unsigned int i = 1; i < rdi(hdr()->e_shnum); ++i)
+        if (rdi(shdrs.at(i).sh_type) == sectionType) return i;
+    return 0;
+}
+
+template<ElfFileParams>
 bool ElfFile<ElfFileParamNames>::hasReplacedSection(const SectionName & sectionName) const
 {
     return replacedSections.count(sectionName);
@@ -1425,12 +1452,24 @@ void ElfFile<ElfFileParamNames>::rewrite
                 if (!shdr) continue;
                 dyn->d_un.d_ptr = (*shdr).get().sh_addr;
             }
-            else if (d_tag == DT_VERNEED)
-                dyn->d_un.d_ptr = findSectionHeader(".gnu.version_r").sh_addr;
-            else if (d_tag == DT_VERDEF)
-                dyn->d_un.d_ptr = findSectionHeader(".gnu.version_d").sh_addr;
-            else if (d_tag == DT_VERSYM)
-                dyn->d_un.d_ptr = findSectionHeader(".gnu.version").sh_addr;
+            else if (d_tag == DT_VERNEED) {
+                auto shdr = tryFindSectionHeader(SHT_GNU_verneed);
+                if (!shdr) shdr = tryFindSectionHeader(SHT_SUNW_verneed);
+                if (!shdr) error("cannot find section corresponding to DT_VERNEED");
+                dyn->d_un.d_ptr = (*shdr).get().sh_addr;
+            }
+            else if (d_tag == DT_VERDEF) {
+                auto shdr = tryFindSectionHeader(SHT_GNU_verdef);
+                if (!shdr) shdr = tryFindSectionHeader(SHT_SUNW_verdef);
+                if (!shdr) error("cannot find section corresponding to DT_VERDEF");
+                dyn->d_un.d_ptr = (*shdr).get().sh_addr;
+            }
+            else if (d_tag == DT_VERSYM) {
+                auto shdr = tryFindSectionHeader(SHT_GNU_versym);
+                if (!shdr) shdr = tryFindSectionHeader(SHT_SUNW_versym);
+                if (!shdr) error("cannot find section corresponding to DT_VERSYM");
+                dyn->d_un.d_ptr = (*shdr).get().sh_addr;
+            }
             /* DT_{PREINIT,INIT,FINI}_ARRAY point at the corresponding
                section's sh_addr and must follow it if relocated
                (https://github.com/NixOS/patchelf/issues/639).
