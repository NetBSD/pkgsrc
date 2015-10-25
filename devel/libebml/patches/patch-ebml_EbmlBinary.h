$NetBSD: patch-ebml_EbmlBinary.h,v 1.2 2015/10/25 09:47:34 wiz Exp $

Add cstdlib for free/malloc.
Needed when compiling with clang/libc++.

https://github.com/Matroska-Org/libebml/pull/13

--- ebml/EbmlBinary.h.orig	2013-04-28 06:51:13.000000000 +0000
+++ ebml/EbmlBinary.h
@@ -37,6 +37,7 @@
 #ifndef LIBEBML_BINARY_H
 #define LIBEBML_BINARY_H
 
+#include <cstdlib>
 #include <cstring>
 
 #include "EbmlTypes.h"
