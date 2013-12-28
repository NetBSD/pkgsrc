$NetBSD: patch-source_libs_uti_sge__loadmem.c,v 1.1 2013/12/28 07:03:11 asau Exp $

--- source/libs/uti/sge_loadmem.c.orig	2011-11-14 19:00:47.000000000 +0000
+++ source/libs/uti/sge_loadmem.c
@@ -29,6 +29,10 @@
  * 
  ************************************************************************/
 /*___INFO__MARK_END__*/
+#if defined(NETBSD)
+#define _KMEMUSER
+#endif
+
 #include <stdio.h>
 #include <string.h>
 
