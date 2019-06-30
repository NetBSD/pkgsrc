$NetBSD: patch-source_Irrlicht_COSOperator.cpp,v 1.1 2019/06/30 22:13:14 nia Exp $

Add missing include.

--- source/Irrlicht/COSOperator.cpp.orig	Sun Jan  6 13:20:50 2013
+++ source/Irrlicht/COSOperator.cpp
@@ -12,6 +12,7 @@
 #include <string.h>
 #include <unistd.h>
 #ifndef _IRR_SOLARIS_PLATFORM_
+#include <sys/param.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
