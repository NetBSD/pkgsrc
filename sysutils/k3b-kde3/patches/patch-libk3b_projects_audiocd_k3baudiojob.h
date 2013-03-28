$NetBSD: patch-libk3b_projects_audiocd_k3baudiojob.h,v 1.1 2013/03/28 21:43:11 joerg Exp $

--- libk3b/projects/audiocd/k3baudiojob.h.orig	2013-03-27 21:08:56.000000000 +0000
+++ libk3b/projects/audiocd/k3baudiojob.h
@@ -29,7 +29,6 @@ class KTempFile;
 class K3bCdrecordWriter;
 class K3bAudioNormalizeJob;
 class K3bAudioJobTempData;
-class K3bDevice::Device;
 class K3bAudioMaxSpeedJob;
 
 /**
