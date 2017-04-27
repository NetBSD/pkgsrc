$NetBSD: patch-mozilla_ipc_chromium_src_base_sys__info__posix.cc,v 1.1 2017/04/27 13:38:18 ryoon Exp $

--- mozilla/ipc/chromium/src/base/sys_info_posix.cc.orig	2016-04-07 21:33:19.000000000 +0000
+++ mozilla/ipc/chromium/src/base/sys_info_posix.cc
@@ -119,7 +119,11 @@ std::wstring SysInfo::GetEnvVar(const wc
 
 // static
 std::string SysInfo::OperatingSystemName() {
+#ifdef OS_SOLARIS
+  struct utsname info;
+#else
   utsname info;
+#endif
   if (uname(&info) < 0) {
     NOTREACHED();
     return "";
