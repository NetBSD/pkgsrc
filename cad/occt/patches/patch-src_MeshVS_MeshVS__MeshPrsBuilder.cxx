$NetBSD: patch-src_MeshVS_MeshVS__MeshPrsBuilder.cxx,v 1.1 2023/02/12 14:42:25 tnn Exp $

Needs alloca.h on SunOS.

--- src/MeshVS/MeshVS_MeshPrsBuilder.cxx.orig	2022-11-11 22:19:44.000000000 +0000
+++ src/MeshVS/MeshVS_MeshPrsBuilder.cxx
@@ -48,6 +48,10 @@
   #include <malloc.h> // for alloca()
 #endif
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 IMPLEMENT_STANDARD_RTTIEXT(MeshVS_MeshPrsBuilder,MeshVS_PrsBuilder)
 
 //================================================================
