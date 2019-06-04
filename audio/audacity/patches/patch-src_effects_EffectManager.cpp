$NetBSD: patch-src_effects_EffectManager.cpp,v 1.3 2019/06/04 23:09:51 nia Exp $

SunOS needs alloca.h for alloca().

--- src/effects/EffectManager.cpp.orig	2019-05-04 10:38:57.000000000 +0000
+++ src/effects/EffectManager.cpp
@@ -27,6 +27,10 @@ effects.
 #include <wx/stopwatch.h>
 #include <wx/tokenzr.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include "../widgets/ErrorDialog.h"
 
 #if defined(EXPERIMENTAL_EFFECTS_RACK)
