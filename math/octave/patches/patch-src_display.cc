$NetBSD: patch-src_display.cc,v 1.1 2015/04/23 06:47:56 dbj Exp $

CGDisplayBitsPerPixel is only good on osx 10.5 or earlier.
CGDisplayModeCopyPixelEncoding should work on 10.6 and later.

--- src/display.cc.orig	2013-02-21 20:19:24.000000000 +0000
+++ src/display.cc
@@ -72,7 +72,16 @@ display_info::init (bool query)
 
       if (display)
         {
-          dp = CGDisplayBitsPerPixel (display);
+          CGDisplayModeRef mode = CGDisplayCopyDisplayMode (display);
+          CFStringRef pixelEncoding = CGDisplayModeCopyPixelEncoding(mode);
+          CFRelease(mode);
+          if (CFStringCompare (pixelEncoding, CFSTR (IO32BitDirectPixels), 0) == 0)
+            dp = 32;
+          else if (CFStringCompare (pixelEncoding, CFSTR (IO16BitDirectPixels), 0) == 0)
+            dp = 16;
+          else
+            dp = 8; // Unknown pixel encoding (probably not really depth 8)
+          CFRelease(pixelEncoding);
 
           ht = CGDisplayPixelsHigh (display);
           wd = CGDisplayPixelsWide (display);
