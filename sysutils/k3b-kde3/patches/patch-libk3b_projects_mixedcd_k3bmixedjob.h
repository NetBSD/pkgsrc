$NetBSD: patch-libk3b_projects_mixedcd_k3bmixedjob.h,v 1.1 2013/03/28 21:43:12 joerg Exp $

--- libk3b/projects/mixedcd/k3bmixedjob.h.orig	2013-03-27 21:09:34.000000000 +0000
+++ libk3b/projects/mixedcd/k3bmixedjob.h
@@ -32,7 +32,6 @@ class K3bCdrecordWriter;
 class K3bMsInfoFetcher;
 class K3bAudioNormalizeJob;
 class K3bAudioJobTempData;
-class K3bDevice::Device;
 
 /**
   *@author Sebastian Trueg
