$NetBSD: patch-src_supertux_error__handler.cpp,v 1.1 2026/03/31 10:47:13 adam Exp $

Fix build.

--- src/supertux/error_handler.cpp.orig	2026-03-31 09:23:40.411242374 +0000
+++ src/supertux/error_handler.cpp
@@ -69,7 +69,7 @@ static PCONTEXT pcontext = NULL;
 static PCONTEXT pcontext = NULL;
 #endif
 
-#ifdef _GNU_SOURCE
+#ifdef __GLIBCXX__
 # include <cxxabi.h>
 #endif
 
