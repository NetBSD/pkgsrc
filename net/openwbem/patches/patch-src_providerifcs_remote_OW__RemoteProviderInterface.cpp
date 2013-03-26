$NetBSD: patch-src_providerifcs_remote_OW__RemoteProviderInterface.cpp,v 1.1 2013/03/26 23:34:35 joerg Exp $

--- src/providerifcs/remote/OW_RemoteProviderInterface.cpp.orig	2013-03-25 15:24:54.000000000 +0000
+++ src/providerifcs/remote/OW_RemoteProviderInterface.cpp
@@ -33,6 +33,7 @@
  */
 
 #include "OW_config.h"
+#include "OW_ClientCIMOMHandle.hpp"
 #include "OW_RemoteProviderInterface.hpp"
 #include "OW_RemoteInstanceProvider.hpp"
 #include "OW_RemoteSecondaryInstanceProvider.hpp"
