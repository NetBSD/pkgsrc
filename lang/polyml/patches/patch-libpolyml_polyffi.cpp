$NetBSD: patch-libpolyml_polyffi.cpp,v 1.1 2020/08/13 23:49:20 dholland Exp $

Fix build failure on amd64 with current libffi.

--- libpolyml/polyffi.cpp~	2017-11-18 13:45:15.000000000 +0000
+++ libpolyml/polyffi.cpp
@@ -109,7 +109,9 @@ static struct _abiTable { const char *ab
 #elif defined(X86_WIN64)
     {"win64", FFI_WIN64},
 #elif defined(X86_ANY)
+#if !defined(X86_64)
     {"sysv", FFI_SYSV},
+#endif
     {"unix64", FFI_UNIX64},
 #endif
     { "default", FFI_DEFAULT_ABI}
