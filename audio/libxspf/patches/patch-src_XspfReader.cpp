$NetBSD: patch-src_XspfReader.cpp,v 1.1 2025/12/16 22:46:05 wiz Exp $

Remove broken uriparser version check.

--- src/XspfReader.cpp.orig	2025-12-16 22:44:25.338208693 +0000
+++ src/XspfReader.cpp
@@ -61,10 +61,6 @@
 #include <cstring> // size_t
 #include <cstddef> // int
 
-#if (URI_VER_MINOR < 7) || ((URI_VER_MINOR == 7) && (URI_VER_RELEASE < 2))
-# error uriparser 0.7.2 or later is required
-#endif
-
 
 namespace {
 
