$NetBSD: patch-fea_io__ip__manager.hh,v 1.1 2020/04/17 00:20:45 joerg Exp $

--- fea/io_ip_manager.hh.orig	2020-04-16 14:48:26.391011767 +0000
+++ fea/io_ip_manager.hh
@@ -22,6 +22,11 @@
 #ifndef __FEA_IO_IP_MANAGER_HH__
 #define __FEA_IO_IP_MANAGER_HH__
 
+#ifdef __NetBSD__
+#include <net/if.h>
+#undef if_name
+#endif
+
 #include <list>
 #include <vector>
 #include <set>
