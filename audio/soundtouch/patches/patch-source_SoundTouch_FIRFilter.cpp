$NetBSD: patch-source_SoundTouch_FIRFilter.cpp,v 1.1 2014/09/23 13:28:54 jperkin Exp $

SunOS needs alloca.h for alloca()

--- source/SoundTouch/FIRFilter.cpp.orig	2014-01-07 20:28:51.000000000 +0000
+++ source/SoundTouch/FIRFilter.cpp
@@ -39,6 +39,9 @@
 //
 ////////////////////////////////////////////////////////////////////////////////
 
+#ifdef __sun
+#include <alloca.h>
+#endif
 #include <memory.h>
 #include <assert.h>
 #include <math.h>
