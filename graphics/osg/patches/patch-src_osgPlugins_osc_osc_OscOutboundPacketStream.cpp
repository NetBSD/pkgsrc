$NetBSD: patch-src_osgPlugins_osc_osc_OscOutboundPacketStream.cpp,v 1.1 2018/08/06 11:12:27 jperkin Exp $

SunOS needs alloca.h

--- src/osgPlugins/osc/osc/OscOutboundPacketStream.cpp.orig	2017-08-28 16:50:49.000000000 +0000
+++ src/osgPlugins/osc/osc/OscOutboundPacketStream.cpp
@@ -35,6 +35,8 @@
 
 #if defined(__WIN32__) || defined(WIN32)
 #include <malloc.h> // for alloca
+#elif defined(__sun)
+#include <alloca.h>
 #endif
 
 #include "OscHostEndianness.h"
