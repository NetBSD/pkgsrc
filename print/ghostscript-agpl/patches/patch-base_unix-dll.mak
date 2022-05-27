$NetBSD: patch-base_unix-dll.mak,v 1.6 2022/05/27 08:26:52 adam Exp $

Use correct shared library naming on Darwin.

--- base/unix-dll.mak.orig	2021-09-27 07:44:02.000000000 +0000
+++ base/unix-dll.mak
@@ -100,10 +100,10 @@ GS_DLLEXT=$(DLL_EXT)
 
 
 # MacOS X
-#GS_SOEXT=dylib
-#GS_SONAME=$(GS_SONAME_BASE).$(GS_SOEXT)
-#GS_SONAME_MAJOR=$(GS_SONAME_BASE).$(GS_VERSION_MAJOR).$(GS_SOEXT)
-#GS_SONAME_MAJOR_MINOR=$(GS_SONAME_BASE).$(GS_VERSION_MAJOR).$(GS_VERSION_MINOR).$(GS_SOEXT)
+#Darwin#GS_SOEXT=dylib
+#Darwin#GS_SONAME=$(GS_SONAME_BASE).$(GS_SOEXT)
+#Darwin#GS_SONAME_MAJOR=$(GS_SONAME_BASE).$(GS_VERSION_MAJOR).$(GS_SOEXT)
+#Darwin#GS_SONAME_MAJOR_MINOR=$(GS_SONAME_BASE).$(GS_VERSION_MAJOR).$(GS_VERSION_MINOR).$(GS_SOEXT)
 #LDFLAGS_SO=-dynamiclib -flat_namespace
 #LDFLAGS_SO_MAC=-dynamiclib -install_name $(GS_SONAME_MAJOR_MINOR)
 #LDFLAGS_SO=-dynamiclib -install_name $(FRAMEWORK_NAME)
