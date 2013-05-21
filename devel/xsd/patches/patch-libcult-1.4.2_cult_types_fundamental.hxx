$NetBSD: patch-libcult-1.4.2_cult_types_fundamental.hxx,v 1.1 2013/05/21 16:36:22 joerg Exp $

--- libcult-1.4.2/cult/types/fundamental.hxx.orig	2013-05-14 19:54:41.000000000 +0000
+++ libcult-1.4.2/cult/types/fundamental.hxx
@@ -7,6 +7,7 @@
 #define CULT_TYPES_FUNDAMENTAL_HXX
 
 #include <cstdlib> // std::size_t, std::ptrdiff_t
+#include <cstddef>
 
 namespace Cult
 {
