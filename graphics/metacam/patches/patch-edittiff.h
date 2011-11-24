$NetBSD: patch-edittiff.h,v 1.1 2011/11/24 13:59:50 joerg Exp $

--- edittiff.h.orig	2011-11-24 02:20:47.000000000 +0000
+++ edittiff.h
@@ -24,6 +24,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #define EDITTIFF_H_INCLUDED
 
 #include "metatiff.h"
+#include <cstdlib>
 
 class _EditIFD;
 
