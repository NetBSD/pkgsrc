$NetBSD: patch-lib_sanitizer__common_sanitizer__linux__libcdep.cpp,v 1.1 2020/04/18 08:03:53 adam Exp $

Fix building on NetBSD.

--- lib/sanitizer_common/sanitizer_linux_libcdep.cpp.orig	2018-10-07 10:50:07.000000000 +0000
+++ lib/sanitizer_common/sanitizer_linux_libcdep.cpp
@@ -520,13 +520,13 @@ void GetThreadStackAndTls(bool main, upt
 #endif
 }
 
-#if !SANITIZER_FREEBSD && !SANITIZER_OPENBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD && !SANITIZER_OPENBSD
 typedef ElfW(Phdr) Elf_Phdr;
 #elif SANITIZER_WORDSIZE == 32 && __FreeBSD_version <= 902001 // v9.2
 #define Elf_Phdr XElf32_Phdr
 #define dl_phdr_info xdl_phdr_info
 #define dl_iterate_phdr(c, b) xdl_iterate_phdr((c), (b))
-#endif // !SANITIZER_FREEBSD && !SANITIZER_OPENBSD
+#endif // !SANITIZER_FREEBSD && !SANITIZER_NETBSD && !SANITIZER_OPENBSD
 
 struct DlIteratePhdrData {
   InternalMmapVectorNoCtor<LoadedModule> *modules;
