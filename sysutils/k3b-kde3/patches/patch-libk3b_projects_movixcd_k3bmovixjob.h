$NetBSD: patch-libk3b_projects_movixcd_k3bmovixjob.h,v 1.1 2013/03/28 21:43:12 joerg Exp $

--- libk3b/projects/movixcd/k3bmovixjob.h.orig	2013-03-27 21:12:37.000000000 +0000
+++ libk3b/projects/movixcd/k3bmovixjob.h
@@ -20,7 +20,6 @@
 #include <k3bjob.h>
 
 class K3bMovixDoc;
-class K3bDevice::Device;
 class K3bDataJob;
 class KTempFile;
 class K3bMovixInstallation;
