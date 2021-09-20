$NetBSD: patch-source_Plugins_ObjectFile_Mach-O_ObjectFileMachO.cpp,v 1.1 2021/09/20 15:53:01 adam Exp $

--- source/Plugins/ObjectFile/Mach-O/ObjectFileMachO.cpp.orig	2021-03-04 11:38:58.000000000 +0000
+++ source/Plugins/ObjectFile/Mach-O/ObjectFileMachO.cpp
@@ -2596,7 +2596,7 @@ size_t ObjectFileMachO::ParseSymtab() {
   typedef std::set<ConstString> IndirectSymbols;
   IndirectSymbols indirect_symbol_names;
 
-#if defined(__APPLE__) && TARGET_OS_EMBEDDED
+#if defined(__APPLE__) && defined(TARGET_OS_EMBEDDED)
 
   // Some recent builds of the dyld_shared_cache (hereafter: DSC) have been
   // optimized by moving LOCAL symbols out of the memory mapped portion of
