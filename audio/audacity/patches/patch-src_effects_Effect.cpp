$NetBSD: patch-src_effects_Effect.cpp,v 1.2 2019/02/10 17:14:42 nia Exp $

SunOS needs alloca.h for alloca().

--- src/effects/Effect.cpp.orig	2018-02-14 07:11:20.000000000 +0000
+++ src/effects/Effect.cpp
@@ -61,6 +61,10 @@ greater use in future.
 #include <Cocoa/Cocoa.h>
 #endif
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include "../Experimental.h"
 #include "../commands/ScreenshotCommand.h"
 
