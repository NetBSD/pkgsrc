$NetBSD: patch-tools_libclang_FatalErrorHandler.cpp,v 1.1 2020/04/18 07:53:38 adam Exp $

Fix error: no member named 'abort' in the global namespace.

--- tools/libclang/FatalErrorHandler.cpp.orig	2020-03-21 13:07:00.218249876 +0000
+++ tools/libclang/FatalErrorHandler.cpp
@@ -9,13 +9,14 @@
 
 #include "clang-c/FatalErrorHandler.h"
 #include "llvm/Support/ErrorHandling.h"
+#include <cstdlib>
 
 static void aborting_fatal_error_handler(void *, const std::string &reason,
                                          bool) {
   // Write the result out to stderr avoiding errs() because raw_ostreams can
   // call report_fatal_error.
   fprintf(stderr, "LIBCLANG FATAL ERROR: %s\n", reason.c_str());
-  ::abort();
+  abort();
 }
 
 extern "C" {
