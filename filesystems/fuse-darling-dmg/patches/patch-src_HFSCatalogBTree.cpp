$NetBSD: patch-src_HFSCatalogBTree.cpp,v 1.1 2020/03/26 02:34:52 joerg Exp $

--- src/HFSCatalogBTree.cpp.orig	2020-03-25 15:29:11.522914079 +0000
+++ src/HFSCatalogBTree.cpp
@@ -5,6 +5,8 @@
 #include <cstring>
 #include "unichar.h"
 
+using icu_64::UnicodeString;
+
 static const int MAX_SYMLINKS = 50;
 
 extern UConverter *g_utf16be;
