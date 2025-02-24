$NetBSD: patch-ThirdParty_ioss_vtkioss_Ioss__FileInfo.C,v 1.1 2025/02/24 17:23:20 adam Exp $

On NetBSD, use statvfs.

--- ThirdParty/ioss/vtkioss/Ioss_FileInfo.C.orig	2025-02-24 16:15:24.332836791 +0000
+++ ThirdParty/ioss/vtkioss/Ioss_FileInfo.C
@@ -39,6 +39,10 @@
 #include <sys/statfs.h>
 #endif
 #endif
+#if defined(__NetBSD__)
+#include <sys/statvfs.h>
+#define statfs statvfs
+#endif
 
 #ifdef SEACAS_HAVE_MPI
 #include <numeric>
