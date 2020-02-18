$NetBSD: patch-src_common.cpp,v 1.1 2020/02/18 22:00:49 maya Exp $

Cast to const char*, makes netbsd (const void* dli_saddr) happier.

--- src/common.cpp.orig	2020-02-12 14:04:07.000000000 +0000
+++ src/common.cpp
@@ -225,7 +225,7 @@ bool is_windows_subsystem_for_linux() {
             swprintf(
                 text, sizeof(text) / sizeof(wchar_t), L"%-3d %s + %td", i - skip_levels,
                 status == 0 ? demangled : info.dli_sname == nullptr ? symbols[i] : info.dli_sname,
-                static_cast<char *>(callstack[i]) - static_cast<char *>(info.dli_saddr));
+                static_cast<char *>(callstack[i]) - static_cast<const char *>(info.dli_saddr));
             free(demangled);
         } else {
             swprintf(text, sizeof(text) / sizeof(wchar_t), L"%-3d %s", i - skip_levels, symbols[i]);
