$NetBSD: patch-src_effects_EffectManager.cpp,v 1.1 2018/07/31 21:10:29 jperkin Exp $

SunOS needs alloca.h for alloca().

--- src/effects/EffectManager.cpp.orig	2016-01-13 14:31:24.000000000 +0000
+++ src/effects/EffectManager.cpp
@@ -15,6 +15,10 @@
 #include <wx/stopwatch.h>
 #include <wx/tokenzr.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include "../Experimental.h"
 
 #if defined(EXPERIMENTAL_EFFECTS_RACK)
