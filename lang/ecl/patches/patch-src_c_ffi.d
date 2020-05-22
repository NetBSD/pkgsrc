$NetBSD: patch-src_c_ffi.d,v 1.1 2020/05/22 01:18:33 joerg Exp $

Match what libffi actually provides.

--- src/c/ffi.d.orig	2020-05-22 00:18:58.780386592 +0000
+++ src/c/ffi.d
@@ -132,7 +132,10 @@ static struct {
   {@':stdcall', FFI_STDCALL},
 #elif defined(X86_WIN64)
   {@':win64', FFI_WIN64},
-#elif defined(X86_ANY) || defined(X86) || defined(X86_64)
+#elif defined(X86_64) || (defined (__x86_64__) && defined (X86_DARWIN))
+  {@':cdecl', FFI_UNIX64},
+  {@':unix64', FFI_UNIX64},
+#elif defined(X86_ANY) || defined(X86)
   {@':cdecl', FFI_SYSV},
   {@':sysv', FFI_SYSV},
   {@':unix64', FFI_UNIX64},
