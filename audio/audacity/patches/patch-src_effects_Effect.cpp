$NetBSD: patch-src_effects_Effect.cpp,v 1.3 2019/06/04 23:09:51 nia Exp $

SunOS needs alloca.h for alloca().

--- src/effects/Effect.cpp.orig	2019-05-04 10:38:57.000000000 +0000
+++ src/effects/Effect.cpp
@@ -78,6 +78,10 @@ greater use in future.
 #include <Cocoa/Cocoa.h>
 #endif
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include "../commands/ScreenshotCommand.h"
 
 #include <unordered_map>
