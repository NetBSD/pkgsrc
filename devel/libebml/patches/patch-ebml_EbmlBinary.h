$NetBSD: patch-ebml_EbmlBinary.h,v 1.1 2013/04/29 21:31:10 joerg Exp $

--- ebml/EbmlBinary.h.orig	2013-04-28 06:51:13.000000000 +0000
+++ ebml/EbmlBinary.h
@@ -37,6 +37,7 @@
 #ifndef LIBEBML_BINARY_H
 #define LIBEBML_BINARY_H
 
+#include <cstdlib>
 #include <cstring>
 
 #include "EbmlTypes.h"
