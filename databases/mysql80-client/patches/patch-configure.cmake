$NetBSD: patch-configure.cmake,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

* check for ffsll and provide a portable version if not found

$NetBSD: patch-configure.cmake,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

--- configure.cmake.orig	2021-03-22 08:44:50.000000000 +0000
+++ configure.cmake
@@ -186,13 +186,9 @@ ENDIF()
 #
 INCLUDE (CheckIncludeFiles)
 
-IF(FREEBSD)
-  # On FreeBSD some includes, e.g. sasl/sasl.h, is in /usr/local/include
-  LIST(APPEND CMAKE_REQUIRED_INCLUDES "/usr/local/include")
-ENDIF()
-
 CHECK_INCLUDE_FILES (alloca.h HAVE_ALLOCA_H)
 CHECK_INCLUDE_FILES (arpa/inet.h HAVE_ARPA_INET_H)
+CHECK_INCLUDE_FILES (bstring.h HAVE_BSTRING_H)
 CHECK_INCLUDE_FILES (dlfcn.h HAVE_DLFCN_H)
 CHECK_INCLUDE_FILES (endian.h HAVE_ENDIAN_H)
 CHECK_INCLUDE_FILES (execinfo.h HAVE_EXECINFO_H)
@@ -241,6 +237,7 @@ CHECK_FUNCTION_EXISTS (fcntl HAVE_FCNTL)
 CHECK_FUNCTION_EXISTS (fdatasync HAVE_FDATASYNC)
 CHECK_SYMBOL_EXISTS(fdatasync "unistd.h" HAVE_DECL_FDATASYNC)
 CHECK_FUNCTION_EXISTS (fedisableexcept HAVE_FEDISABLEEXCEPT)
+CHECK_FUNCTION_EXISTS (ffsll HAVE_FFSLL)
 CHECK_FUNCTION_EXISTS (fsync HAVE_FSYNC)
 CHECK_FUNCTION_EXISTS (gethrtime HAVE_GETHRTIME)
 CHECK_FUNCTION_EXISTS (getpass HAVE_GETPASS)
