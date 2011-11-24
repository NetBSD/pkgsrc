$NetBSD: patch-datatiff.h,v 1.1 2011/11/24 13:59:50 joerg Exp $

--- datatiff.h.orig	2011-11-24 02:20:21.000000000 +0000
+++ datatiff.h
@@ -24,6 +24,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #define DATATIFF_H_INCLUDED
 
 #include "metatiff.h"
+#include <cstdlib>
 
 class _DataIFD;
 class _DataIFDEntry;
