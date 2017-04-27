$NetBSD: patch-mozilla_xpcom_build_XPCOMInit.cpp,v 1.3 2017/04/27 13:32:41 ryoon Exp $

--- mozilla/xpcom/build/XPCOMInit.cpp.orig	2017-04-14 04:53:30.000000000 +0000
+++ mozilla/xpcom/build/XPCOMInit.cpp
@@ -154,7 +154,9 @@ extern nsresult nsStringInputStreamConst
 
 #include "mozilla/ipc/GeckoChildProcessHost.h"
 
+#ifndef MOZ_OGG_NO_MEM_REPORTING
 #include "ogg/ogg.h"
+#endif
 #if defined(MOZ_VPX) && !defined(MOZ_VPX_NO_MEM_REPORTING)
 #if defined(HAVE_STDINT_H)
 // mozilla-config.h defines HAVE_STDINT_H, and then it's defined *again* in
@@ -675,11 +677,13 @@ NS_InitXPCOM2(nsIServiceManager** aResul
   // this oddness.
   mozilla::SetICUMemoryFunctions();
 
+#ifndef MOZ_OGG_NO_MEM_REPORTING
   // Do the same for libogg.
   ogg_set_mem_functions(OggReporter::CountingMalloc,
                         OggReporter::CountingCalloc,
                         OggReporter::CountingRealloc,
                         OggReporter::CountingFree);
+#endif
 
 #if defined(MOZ_VPX) && !defined(MOZ_VPX_NO_MEM_REPORTING)
   // And for VPX.
