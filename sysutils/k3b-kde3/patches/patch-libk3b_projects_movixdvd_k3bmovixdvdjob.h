$NetBSD: patch-libk3b_projects_movixdvd_k3bmovixdvdjob.h,v 1.1 2013/03/28 21:43:12 joerg Exp $

--- libk3b/projects/movixdvd/k3bmovixdvdjob.h.orig	2013-03-27 21:11:36.000000000 +0000
+++ libk3b/projects/movixdvd/k3bmovixdvdjob.h
@@ -20,7 +20,6 @@
 #include <k3bjob.h>
 
 class K3bMovixDvdDoc;
-class K3bDevice::Device;
 class K3bDvdJob;
 class KTempFile;
 class K3bMovixInstallation;
