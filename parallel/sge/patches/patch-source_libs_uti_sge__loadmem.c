$NetBSD: patch-source_libs_uti_sge__loadmem.c,v 1.2 2014/01/14 10:21:39 markd Exp $

--- source/libs/uti/sge_loadmem.c.orig	2013-10-28 16:22:54.000000000 +0000
+++ source/libs/uti/sge_loadmem.c
@@ -45,6 +45,10 @@
 #include "uti/sge_log.h"
 #include "uti/msg_utilib.h"
 
+#ifdef __NetBSD__
+#include <uvm/uvm_extern.h>
+#endif
+
 #if !defined(__linux__) && !defined(DARWIN) && !defined(FREEBSD) && !defined(NETBSD)
 
 #include <unistd.h>
