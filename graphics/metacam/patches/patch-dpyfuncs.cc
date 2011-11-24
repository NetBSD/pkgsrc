$NetBSD: patch-dpyfuncs.cc,v 1.1 2011/11/24 13:59:50 joerg Exp $

--- dpyfuncs.cc.orig	2011-11-24 02:18:52.000000000 +0000
+++ dpyfuncs.cc
@@ -24,6 +24,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #include <math.h>
 #include <cstdio>
 #include <ctype.h>
+#include <cstring>
 
 #include "metacam.h"
 #include "dpyfuncs.h"
