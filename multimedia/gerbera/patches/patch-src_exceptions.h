$NetBSD: patch-src_exceptions.h,v 1.1 2026/06/25 08:16:53 wiz Exp $

Fix build.
https://github.com/gerbera/gerbera/issues/3897

--- src/exceptions.h.orig	2026-06-25 08:08:45.581012687 +0000
+++ src/exceptions.h
@@ -35,6 +35,7 @@
 #define __EXCEPTIONS_H__
 
 #include <fmt/core.h>
+#include <fmt/format.h>
 #include <stdexcept>
 #include <string>
 
