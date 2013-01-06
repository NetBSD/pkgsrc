$NetBSD: patch-lib_irrlicht_source_Irrlicht_COSOperator.cpp,v 1.1 2013/01/06 15:16:20 ryoon Exp $

* Fix build on OpenBSD/amd64 5.2 at least

--- lib/irrlicht/source/Irrlicht/COSOperator.cpp.orig	Sun Jan  6 09:39:08 2013
+++ lib/irrlicht/source/Irrlicht/COSOperator.cpp
@@ -12,6 +12,7 @@
 #include <string.h>
 #include <unistd.h>
 #ifndef _IRR_SOLARIS_PLATFORM_
+#include <sys/param.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
