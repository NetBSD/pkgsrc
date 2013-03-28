$NetBSD: patch-libk3b_projects_k3bcdrecordwriter.h,v 1.1 2013/03/28 21:43:12 joerg Exp $

--- libk3b/projects/k3bcdrecordwriter.h.orig	2013-03-27 21:05:09.000000000 +0000
+++ libk3b/projects/k3bcdrecordwriter.h
@@ -25,7 +25,6 @@
 class K3bExternalBin;
 class K3bProcess;
 class KProcess;
-class K3bDevice::Device;
 
 
 class K3bCdrecordWriter : public K3bAbstractWriter
