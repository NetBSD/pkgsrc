$NetBSD: patch-usecode_useval.h,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- usecode/useval.h.orig	2011-11-25 17:54:48.000000000 +0000
+++ usecode/useval.h
@@ -23,6 +23,7 @@
 #define USEVAL_H	1
 
 #include <cassert>
+#include <cstdlib>
 #include <iostream>
 
 #include <vector>	// STL container
