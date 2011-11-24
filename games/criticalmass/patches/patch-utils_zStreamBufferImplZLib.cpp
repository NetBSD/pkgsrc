$NetBSD: patch-utils_zStreamBufferImplZLib.cpp,v 1.1 2011/11/24 14:09:47 joerg Exp $

--- utils/zStreamBufferImplZLib.cpp.orig	2011-11-24 00:46:30.000000000 +0000
+++ utils/zStreamBufferImplZLib.cpp
@@ -14,6 +14,7 @@
 //
 #include <Trace.hpp>
 #include <zStreamBufferImplZLib.hpp>
+#include <stdlib.h>
 
 bool ziStreamBufferImplZLib::init( void)
 {
