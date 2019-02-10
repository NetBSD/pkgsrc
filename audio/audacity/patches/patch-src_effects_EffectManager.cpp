$NetBSD: patch-src_effects_EffectManager.cpp,v 1.2 2019/02/10 17:14:42 nia Exp $

SunOS needs alloca.h for alloca().

--- src/effects/EffectManager.cpp.orig	2018-02-14 07:11:20.000000000 +0000
+++ src/effects/EffectManager.cpp
@@ -15,6 +15,10 @@
 #include <wx/stopwatch.h>
 #include <wx/tokenzr.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include "../Experimental.h"
 #include "../widgets/ErrorDialog.h"
 
