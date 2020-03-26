$NetBSD: patch-src_HFSAttributeBTree.cpp,v 1.1 2020/03/26 02:34:52 joerg Exp $

--- src/HFSAttributeBTree.cpp.orig	2020-03-25 15:29:52.355921486 +0000
+++ src/HFSAttributeBTree.cpp
@@ -4,6 +4,8 @@
 #include <unicode/unistr.h>
 #include "unichar.h"
 
+using icu_64::UnicodeString;
+
 HFSAttributeBTree::HFSAttributeBTree(std::shared_ptr<HFSFork> fork, CacheZone* zone)
 : HFSBTree(fork, zone, "Attribute")
 {
