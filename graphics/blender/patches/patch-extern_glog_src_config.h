$NetBSD: patch-extern_glog_src_config.h,v 1.1 2016/08/15 19:26:18 ryoon Exp $

--- extern/glog/src/config.h.orig	2016-03-23 08:49:49.000000000 +0000
+++ extern/glog/src/config.h
@@ -10,6 +10,8 @@
  #include "windows/config.h"
 #elif defined(__linux__)
  #include "config_linux.h"
+#elif defined(__NetBSD__)
+ #include "config_netbsd.h"
 #elif defined(_MSC_VER)
  #include "windows/config.h"
 #elif defined(__GNU__)
