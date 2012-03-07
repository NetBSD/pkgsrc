$NetBSD: patch-src_osgViewer_DarwinUtils.mm,v 1.1 2012/03/07 16:27:35 adam Exp $

Work around depreciated API.

--- src/osgViewer/DarwinUtils.mm.orig	2012-03-06 14:49:28.000000000 +0000
+++ src/osgViewer/DarwinUtils.mm
@@ -313,7 +313,11 @@ void DarwinWindowingSystemInterface::get
     CGDirectDisplayID id = getDisplayID(si);
     resolution.width = CGDisplayPixelsWide(id);
     resolution.height = CGDisplayPixelsHigh(id);
-    resolution.colorDepth = CGDisplayBitsPerPixel(id);
+    CGDisplayModeRef displayMode = CGDisplayCopyDisplayMode(id);
+    CFStringRef pixelEncoding = CGDisplayModeCopyPixelEncoding(displayMode);
+    CGDisplayModeRelease(displayMode);
+    resolution.colorDepth = CFStringGetLength(pixelEncoding);
+    CFRelease(pixelEncoding);
     resolution.refreshRate = getDictDouble (CGDisplayCurrentMode(id), kCGDisplayRefreshRate);        // Not tested
     if (resolution.refreshRate<0) resolution.refreshRate = 0;
 }
@@ -402,7 +406,7 @@ bool DarwinWindowingSystemInterface::set
     CFDictionaryRef display_mode_values =
         CGDisplayBestModeForParametersAndRefreshRate(
                         displayid, 
-                        CGDisplayBitsPerPixel(displayid), 
+                        32, 
                         width, height,  
                         refresh,  
                         NULL);
@@ -432,7 +436,7 @@ bool DarwinWindowingSystemInterface::set
     CFDictionaryRef display_mode_values =
         CGDisplayBestModeForParametersAndRefreshRate(
                         displayid, 
-                        CGDisplayBitsPerPixel(displayid), 
+                        32, 
                         width, height,  
                         refreshRate,  
                         &success);
