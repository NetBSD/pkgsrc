$NetBSD: patch-source_SoundTouch_SoundTouch.cpp,v 1.1 2014/09/23 13:28:54 jperkin Exp $

SunOS needs alloca.h for alloca()

--- source/SoundTouch/SoundTouch.cpp.orig	2014-01-07 20:28:51.000000000 +0000
+++ source/SoundTouch/SoundTouch.cpp
@@ -69,6 +69,9 @@
 //
 ////////////////////////////////////////////////////////////////////////////////
 
+#ifdef __sun
+#include <alloca.h>
+#endif
 #include <assert.h>
 #include <stdlib.h>
 #include <memory.h>
