$NetBSD: patch-src_unrardll_wrapper.cpp,v 1.1 2022/01/17 17:47:52 rhialto Exp $

Strangely enough, libunrar headers are not installed in a subdirectory.

--- src/unrardll/wrapper.cpp.orig	2020-11-07 08:29:50.000000000 +0000
+++ src/unrardll/wrapper.cpp
@@ -16,7 +16,7 @@
 #else
 #include <unistd.h>
 #endif
-#include <unrar/dll.hpp>
+#include <dll.hpp>
 #include <errno.h>
 
 #define CALLBACK_ERROR_SZ 256
