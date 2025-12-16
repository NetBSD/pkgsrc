$NetBSD: patch-src_SpiffReader.cpp,v 1.1 2025/12/16 22:43:49 wiz Exp $

Remove broken uriparser version test.

--- src/SpiffReader.cpp.orig	2025-12-16 22:42:36.422468743 +0000
+++ src/SpiffReader.cpp
@@ -61,10 +61,6 @@
 #include <cstring> // size_t
 #include <cstddef> // int
 
-#if (URI_VER_MINOR < 7) || ((URI_VER_MINOR == 7) && (URI_VER_RELEASE < 2))
-# error uriparser 0.7.2 or later is required
-#endif
-
 
 namespace {
 
