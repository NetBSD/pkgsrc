$NetBSD: patch-RenderTexture.cpp,v 1.1 2012/02/28 10:42:13 reinoud Exp $

--- RenderTexture/RenderTexture.cpp.orig	2011-12-01 21:25:12.000000000 +0000
+++ RenderTexture/RenderTexture.cpp
@@ -414,11 +414,13 @@ bool RenderTexture::Initialize(int width
     GLXFBConfigSGIX *fbConfigs;
     int nConfigs;
 
+#if 0
     // [Andrew Wood]
     //Add in pbufferAttribs. Needed  to choose pixel format. (Especially for floating point)
     _pixelFormatAttribs.insert(_pixelFormatAttribs.begin(),
 			       _pbufferAttribs.begin(),_pbufferAttribs.end());
     // [/Andrew Wood]
+#endif
     
     fbConfigs = glXChooseFBConfigSGIX(_pDisplay, screen, 
                                       &_pixelFormatAttribs[0], &nConfigs);
