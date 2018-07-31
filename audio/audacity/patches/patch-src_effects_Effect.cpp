$NetBSD: patch-src_effects_Effect.cpp,v 1.1 2018/07/31 21:10:29 jperkin Exp $

SunOS needs alloca.h for alloca().

--- src/effects/Effect.cpp.orig	2016-01-13 14:31:24.000000000 +0000
+++ src/effects/Effect.cpp
@@ -54,6 +54,10 @@ greater use in future.
 #include <Cocoa/Cocoa.h>
 #endif
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include "../Experimental.h"
 
 static const int kDummyID = 20000;
