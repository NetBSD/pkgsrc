$NetBSD: patch-deps_v8_third__party_abseil-cpp_absl_debugging_internal_elf__mem__image.h,v 1.1 2024/11/27 17:07:15 riastradh Exp $

Work around missing DT_GNU_HASH definition in NetBSD 9:

../deps/v8/third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.cc: In member function 'void absl::debugging_internal::ElfMemImage::Init(const void*)':
../deps/v8/third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.cc:228:12: error: 'DT_GNU_HASH' was not declared in this scope; did you mean 'SHT_GNU_HASH'?
  228 |       case DT_GNU_HASH:
      |            ^~~~~~~~~~~
      |            SHT_GNU_HASH

--- deps/v8/third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h.orig	2024-11-20 14:52:46.000000000 +0000
+++ deps/v8/third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h
@@ -47,6 +47,10 @@
 #define ElfW(x) __ElfN(x)
 #endif
 
+#if defined(__NetBSD__) && !defined(DT_GNU_HASH)
+#define DT_GNU_HASH 0x6ffffef5
+#endif
+
 namespace absl {
 ABSL_NAMESPACE_BEGIN
 namespace debugging_internal {
