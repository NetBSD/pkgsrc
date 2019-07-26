$NetBSD: patch-lib_vamp_src_vamp-hostsdk_PluginHostAdapter.cpp,v 1.1 2019/07/26 23:35:09 nia Exp $

Remove silly version checking.

--- lib/vamp/src/vamp-hostsdk/PluginHostAdapter.cpp.orig	2019-04-22 07:50:04.000000000 +0000
+++ lib/vamp/src/vamp-hostsdk/PluginHostAdapter.cpp
@@ -37,10 +37,6 @@
 #include <vamp-hostsdk/PluginHostAdapter.h>
 #include <cstdlib>
 
-#if ( VAMP_SDK_MAJOR_VERSION != 2 || VAMP_SDK_MINOR_VERSION != 7 )
-#error Unexpected version of Vamp SDK header included
-#endif
-
 _VAMP_SDK_HOSTSPACE_BEGIN(PluginHostAdapter.cpp)
 
 namespace Vamp
