$NetBSD: patch-src_largeobject.cxx,v 1.2 2013/02/12 04:35:24 hiramatsu Exp $

Fix build with modern GCC.

--- src/largeobject.cxx.orig	2013-02-11 10:36:16.000000000 +0000
+++ src/largeobject.cxx
@@ -18,6 +18,7 @@
 #include "pqxx/compiler-internal.hxx"
 
 #include <cerrno>
+#include <cstring>
 #include <stdexcept>
 
 #include "libpq-fe.h"
