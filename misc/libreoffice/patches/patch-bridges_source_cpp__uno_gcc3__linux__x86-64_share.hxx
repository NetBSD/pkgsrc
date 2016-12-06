$NetBSD: patch-bridges_source_cpp__uno_gcc3__linux__x86-64_share.hxx,v 1.4 2016/12/06 15:21:00 ryoon Exp $

* NetBSD has no _Unwind_Exception

--- bridges/source/cpp_uno/gcc3_linux_x86-64/share.hxx.orig	2016-10-28 14:50:26.000000000 +0000
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/share.hxx
@@ -105,6 +105,16 @@ public:
 // <https://mentorembedded.github.io/cxx-abi/abi-eh.html>,
 // libcxxabi/src/cxa_exception.hpp:
 namespace __cxxabiv1 {
+#if defined(__NetBSD__)
+struct _Unwind_Exception
+{
+    unsigned exception_class __attribute__((__mode__(__DI__)));
+    void * exception_cleanup;
+    unsigned private_1 __attribute__((__mode__(__word__)));
+    unsigned private_2 __attribute__((__mode__(__word__)));
+} __attribute__((__aligned__));
+#endif
+
 struct __cxa_exception {
 #if defined _LIBCPPABI_VERSION // detect libc++abi
 #if defined __LP64__ || LIBCXXABI_ARM_EHABI
