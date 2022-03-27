$NetBSD: patch-src_lib_fcitx-utils_library.cpp,v 1.1 2022/03/27 12:45:04 tnn Exp $

Fix build on SunOS

--- src/lib/fcitx-utils/library.cpp.orig	2020-08-06 00:46:06.006403400 +0000
+++ src/lib/fcitx-utils/library.cpp
@@ -64,7 +64,7 @@ bool Library::load(Flags<fcitx::LibraryL
         flag |= RTLD_GLOBAL;
     }
 
-#ifdef HAS_DLMOPEN
+#if defined(HAS_DLMOPEN) && defined(LM_ID_NEWLM)
     if (hint & LibraryLoadHint::NewNameSpace) {
         // allow dlopen self
         d->handle_ = dlmopen(
@@ -173,7 +173,7 @@ std::string Library::error() {
 }
 
 bool Library::isNewNamespaceSupported() {
-#ifdef HAS_DLMOPEN
+#if defined(HAS_DLMOPEN) && defined(LM_ID_NEWLM)
     return true;
 #else
     return false;
