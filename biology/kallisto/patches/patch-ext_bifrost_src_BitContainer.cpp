$NetBSD: patch-ext_bifrost_src_BitContainer.cpp,v 1.2 2024/07/27 12:22:54 bacon Exp $

# vfscanf() not found on NetBSD 9

--- ext/bifrost/src/BitContainer.cpp.orig	2023-11-01 12:46:19.000000000 +0000
+++ ext/bifrost/src/BitContainer.cpp
@@ -1,3 +1,4 @@
+#include <cstdio>
 #include "BitContainer.hpp"
 
 BitContainer::BitContainer() : setBits(localBitVector) {}
