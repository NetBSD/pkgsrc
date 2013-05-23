$NetBSD: patch-source_libs_uti_sge__loadmem.c,v 1.1 2013/05/23 18:41:48 joerg Exp $

--- source/libs/uti/sge_loadmem.c.orig	2013-05-23 16:27:21.000000000 +0000
+++ source/libs/uti/sge_loadmem.c
@@ -44,6 +44,10 @@
 #include "uti/sge_log.h"
 #include "uti/msg_utilib.h"
 
+#ifdef __NetBSD__
+#include <uvm/uvm_extern.h>
+#endif
+
 #if !defined(LINUX) && !defined(CRAY) && !defined(DARWIN) && !defined(FREEBSD) && !defined(NETBSD)
 
 #include <unistd.h>
