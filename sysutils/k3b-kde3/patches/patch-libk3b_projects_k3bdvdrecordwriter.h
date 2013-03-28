$NetBSD: patch-libk3b_projects_k3bdvdrecordwriter.h,v 1.1 2013/03/28 21:43:12 joerg Exp $

--- libk3b/projects/k3bdvdrecordwriter.h.orig	2013-03-27 21:16:40.000000000 +0000
+++ libk3b/projects/k3bdvdrecordwriter.h
@@ -18,9 +18,6 @@
 
 #include "k3bcdrecordwriter.h"
 
-
-class K3bDevice::Device;
-
 /**
  * Basically this is just a wrapper around K3bCdrecordWriter
  * which uses another K3bExternalBin and ignores the writingMode setting.
