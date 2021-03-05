$NetBSD: patch-src_common.cpp,v 1.2 2021/03/05 08:47:29 nia Exp $

Cast to const char*, makes netbsd (const void* dli_saddr) happier.

--- src/common.cpp.orig	2021-03-01 12:47:02.000000000 +0000
+++ src/common.cpp
@@ -212,7 +212,7 @@ bool is_windows_subsystem_for_linux() {
                      status == 0                 ? demangled
                      : info.dli_sname == nullptr ? symbols[i]
                                                  : info.dli_sname,
-                     static_cast<char *>(callstack[i]) - static_cast<char *>(info.dli_saddr));
+                     static_cast<char *>(callstack[i]) - static_cast<const char *>(info.dli_saddr));
             free(demangled);
         } else {
             swprintf(text, sizeof(text) / sizeof(wchar_t), L"%-3d %s", i - skip_levels, symbols[i]);
