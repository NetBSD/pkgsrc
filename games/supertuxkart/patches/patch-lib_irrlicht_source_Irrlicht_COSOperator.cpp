$NetBSD: patch-lib_irrlicht_source_Irrlicht_COSOperator.cpp,v 1.2 2014/01/01 02:46:49 ryoon Exp $

* Fix build on OpenBSD/amd64 5.2 at least

--- lib/irrlicht/source/Irrlicht/COSOperator.cpp.orig	2013-12-31 07:04:37.000000000 +0000
+++ lib/irrlicht/source/Irrlicht/COSOperator.cpp
@@ -12,6 +12,7 @@
 #include <string.h>
 #include <unistd.h>
 #ifndef _IRR_SOLARIS_PLATFORM_
+#include <sys/param.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
