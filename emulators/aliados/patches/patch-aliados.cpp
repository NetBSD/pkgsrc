$NetBSD: patch-aliados.cpp,v 1.1 2011/11/23 23:27:07 joerg Exp $

--- aliados.cpp.orig	2004-03-20 19:35:40.000000000 +0000
+++ aliados.cpp
@@ -14,6 +14,7 @@ using std::endl;
 using std::flush;
 #include <stdexcept>
 #include <memory>
+#include <stdlib.h>
 
 namespace {
 
