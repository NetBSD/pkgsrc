$NetBSD: patch-extern_libmv_third__party_glog_src_config.h,v 1.1 2012/12/03 13:15:51 ryoon Exp $

* Load NetBSD config file

--- extern/libmv/third_party/glog/src/config.h.orig	2012-10-09 18:43:15.000000000 +0000
+++ extern/libmv/third_party/glog/src/config.h
@@ -6,6 +6,8 @@
  #include "config_mac.h"
 #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
  #include "config_freebsd.h"
+#elif defined(__NetBSD__)
+ #include "config_netbsd.h"
 #elif defined(__MINGW32__)
  #include "windows/config.h"
 #elif defined(__linux__)
