$NetBSD: patch-common_alformat.hpp,v 1.1 2025/12/23 12:21:08 abs Exp $

Gcc only supports c++20's "std:format" from gcc 13 or later

--- common/alformat.hpp.orig	2025-12-23 12:14:45.974131386 +0000
+++ common/alformat.hpp
@@ -8,7 +8,7 @@
 /* On macOS, std::format requires std::to_chars, which isn't available prior
  * to macOS 13.3.
  */
-#if defined(MAC_OS_X_VERSION_MIN_REQUIRED) && MAC_OS_X_VERSION_MIN_REQUIRED < 130300
+#if (defined(MAC_OS_X_VERSION_MIN_REQUIRED) && MAC_OS_X_VERSION_MIN_REQUIRED < 130300) || (defined(__GNUC__) && __GNUC__ < 13)
 #include "fmt/format.h"
 
 namespace al {
