$NetBSD: patch-source_libs_uti_sge__loadmem.c,v 1.3 2022/04/02 11:48:20 nia Exp $

_KMEMUSER is defined too late which causes vaddr_t to be undefined
by the time machine/types.h is included.

--- source/libs/uti/sge_loadmem.c.orig	2013-10-28 16:22:54.000000000 +0000
+++ source/libs/uti/sge_loadmem.c
@@ -29,6 +29,9 @@
  * 
  ************************************************************************/
 /*___INFO__MARK_END__*/
+#ifdef __NetBSD__
+#define _KMEMUSER
+#endif
 #include <stdio.h>
 #include <string.h>
 #include <locale.h>
@@ -45,6 +48,10 @@
 #include "uti/sge_log.h"
 #include "uti/msg_utilib.h"
 
+#ifdef __NetBSD__
+#include <uvm/uvm_extern.h>
+#endif
+
 #if !defined(__linux__) && !defined(DARWIN) && !defined(FREEBSD) && !defined(NETBSD)
 
 #include <unistd.h>
@@ -620,7 +627,7 @@ int sge_loadmem(sge_mem_info_t *mem_info
 
 #if defined(NETBSD)
 
-#define _KMEMUSER                                                              
+#include <machine/types.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
 
