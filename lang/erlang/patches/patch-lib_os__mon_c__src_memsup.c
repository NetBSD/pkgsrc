$NetBSD: patch-lib_os__mon_c__src_memsup.c,v 1.1 2013/01/11 13:28:36 joerg Exp $

--- lib/os_mon/c_src/memsup.c.orig	2013-01-11 11:51:56.000000000 +0000
+++ lib/os_mon/c_src/memsup.c
@@ -116,6 +116,9 @@
 #if !defined (__OpenBSD__) && !defined (__NetBSD__) 
 #include <vm/vm_param.h>
 #endif
+#if defined (__NetBSD__)
+#include <sys/vmmeter.h>
+#endif
 #if defined (__FreeBSD__) || defined(__DragonFly__)
 #include <sys/vmmeter.h>
 #endif
