$NetBSD: patch-src_main.cpp,v 1.1 2026/04/06 13:46:38 nia Exp $

Load the libs from our own isolated directory.

--- src/main.cpp.orig	2026-04-06 12:01:44.350189123 +0000
+++ src/main.cpp
@@ -81,7 +81,7 @@ class ProtocolFactory : public ProtocolBaseFactory (pu
     std::shared_ptr<T> protocol;
 #ifdef HAS_DYNAMICLOAD
     std::string libPath =
-      FileUtil::DirName(FileUtil::GetSelfPath()) + "/../" CMAKE_INSTALL_LIBDIR "/" + T::GetLibName() +
+      FileUtil::DirName(FileUtil::GetSelfPath()) + "/../" CMAKE_INSTALL_LIBDIR "/nchat/" + T::GetLibName() +
       FileUtil::GetLibSuffix();
     std::string createFunc = T::GetCreateFunc();
     void* handle = dlopen(libPath.c_str(), RTLD_LAZY);
