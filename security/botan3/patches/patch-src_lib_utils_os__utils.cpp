$NetBSD: patch-src_lib_utils_os__utils.cpp,v 1.2 2023/10/19 15:21:40 wiz Exp $

Fix build on NetBSD.
https://github.com/randombit/botan/pull/3767

--- src/lib/utils/os_utils.cpp.orig	2023-10-09 07:33:53.000000000 +0000
+++ src/lib/utils/os_utils.cpp
@@ -626,7 +626,7 @@ void OS::set_thread_name(std::thread& th
    #elif defined(BOTAN_TARGET_OS_IS_OPENBSD)
    static_cast<void>(pthread_set_name_np(thread.native_handle(), name.c_str()));
    #elif defined(BOTAN_TARGET_OS_IS_NETBSD)
-   static_cast<void>(pthread_set_name_np(thread.native_handle(), "%s", const_cast<char*>(name.c_str())));
+   static_cast<void>(pthread_setname_np(thread.native_handle(), "%s", const_cast<char*>(name.c_str())));
    #elif defined(BOTAN_TARGET_OS_HAS_WIN32) && defined(BOTAN_BUILD_COMPILER_IS_MSVC)
    typedef HRESULT(WINAPI * std_proc)(HANDLE, PCWSTR);
    HMODULE kern = GetModuleHandleA("KernelBase.dll");
