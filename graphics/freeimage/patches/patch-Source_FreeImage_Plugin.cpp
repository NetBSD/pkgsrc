$NetBSD: patch-Source_FreeImage_Plugin.cpp,v 1.1 2020/05/14 16:42:14 nia Exp $

Unbundle image libraries.

--- Source/FreeImage/Plugin.cpp.orig	2017-02-18 15:09:28.000000000 +0000
+++ Source/FreeImage/Plugin.cpp
@@ -263,7 +263,12 @@ FreeImage_Initialise(BOOL load_local_plu
 			s_plugins->AddNode(InitDDS);
 	        s_plugins->AddNode(InitGIF);
 	        s_plugins->AddNode(InitHDR);
-			s_plugins->AddNode(InitG3);
+/* The G3 fax format plugin is deliberately disabled in the build of
+   FreeImage as it requires that FreeImage uses a private copy of libtiff
+   which is a no no because of security reasons. */
+#if 0
+ 			s_plugins->AddNode(InitG3);
+#endif
 			s_plugins->AddNode(InitSGI);
 			s_plugins->AddNode(InitEXR);
 			s_plugins->AddNode(InitJ2K);
@@ -272,7 +277,7 @@ FreeImage_Initialise(BOOL load_local_plu
 			s_plugins->AddNode(InitPICT);
 			s_plugins->AddNode(InitRAW);
 			s_plugins->AddNode(InitWEBP);
-#if !(defined(_MSC_VER) && (_MSC_VER <= 1310))
+#if 0
 			s_plugins->AddNode(InitJXR);
 #endif // unsupported by MS Visual Studio 2003 !!!
 			
