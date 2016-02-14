$NetBSD: patch-ipc_glue_ScopedXREEmbed.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

Walking out of [subprocess].app/Contents/MacOS would only be needed if
we were using the cocoa toolkit.

--- ipc/glue/ScopedXREEmbed.cpp.orig	2014-05-06 22:55:41.000000000 +0000
+++ ipc/glue/ScopedXREEmbed.cpp
@@ -66,7 +66,7 @@ ScopedXREEmbed::Start()
   localFile = do_QueryInterface(parent);
   NS_ENSURE_TRUE_VOID(localFile);
 
-#ifdef OS_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (XRE_GetProcessType() == GeckoProcessType_Content) {
     // We're an XPCOM-using subprocess.  Walk out of
     // [subprocess].app/Contents/MacOS to the real GRE dir.
