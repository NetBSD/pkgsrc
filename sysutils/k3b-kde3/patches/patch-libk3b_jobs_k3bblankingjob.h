$NetBSD: patch-libk3b_jobs_k3bblankingjob.h,v 1.1 2013/03/28 21:43:11 joerg Exp $

--- libk3b/jobs/k3bblankingjob.h.orig	2013-03-28 15:19:26.000000000 +0000
+++ libk3b/jobs/k3bblankingjob.h
@@ -20,7 +20,6 @@
 #include "k3b_export.h"
 class KProcess;
 class QString;
-class K3bDevice::Device;
 class K3bAbstractWriter;
 
 
