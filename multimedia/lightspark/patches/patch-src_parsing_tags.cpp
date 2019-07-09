$NetBSD: patch-src_parsing_tags.cpp,v 1.1 2019/07/09 16:33:30 nia Exp $

NetBSD has alloca in stdlib.h, not alloca.h.

--- src/parsing/tags.cpp.orig	2018-06-02 09:25:36.000000000 +0000
+++ src/parsing/tags.cpp
@@ -23,6 +23,8 @@
 #include <sstream>
 #ifdef __MINGW32__
 #include <malloc.h>
+#elif !defined(__GLIBC__) && !defined(__sun)
+#include <stdlib.h>
 #else
 #include <alloca.h>
 #endif
