$NetBSD: patch-fea_io__link.hh,v 1.1 2020/04/17 00:20:45 joerg Exp $

--- fea/io_link.hh.orig	2020-04-16 14:47:26.780539843 +0000
+++ fea/io_link.hh
@@ -23,6 +23,11 @@
 #ifndef __FEA_IO_LINK_HH__
 #define __FEA_IO_LINK_HH__
 
+#ifdef __NetBSD__
+#include <net/if.h>
+#undef if_name
+#endif
+
 #include <vector>
 
 #include "fea_data_plane_manager.hh"
