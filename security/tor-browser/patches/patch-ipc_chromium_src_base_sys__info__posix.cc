$NetBSD: patch-ipc_chromium_src_base_sys__info__posix.cc,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- ipc/chromium/src/base/sys_info_posix.cc.orig	2014-04-18 02:03:04.000000000 +0000
+++ ipc/chromium/src/base/sys_info_posix.cc
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
@@ -129,7 +133,11 @@ std::string SysInfo::OperatingSystemName
 
 // static
 std::string SysInfo::OperatingSystemVersion() {
+#ifdef OS_SOLARIS
+  struct utsname info;
+#else
   utsname info;
+#endif
   if (uname(&info) < 0) {
     NOTREACHED();
     return "";
