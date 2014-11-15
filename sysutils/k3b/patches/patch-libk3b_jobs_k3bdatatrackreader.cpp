$NetBSD: patch-libk3b_jobs_k3bdatatrackreader.cpp,v 1.2 2014/11/15 03:35:26 markd Exp $

--- libk3b/jobs/k3bdatatrackreader.cpp.orig	2014-11-04 18:37:31.000000000 +0000
+++ libk3b/jobs/k3bdatatrackreader.cpp
@@ -256,7 +256,7 @@ bool K3b::DataTrackReader::run()
     //
     d->device->setSpeed( 0xffff, 0xffff );
 
-#ifdef __NETBSD__
+#ifdef Q_OS_NETBSD
     s_bufferSizeSectors = 31;
 #else
     s_bufferSizeSectors = 128;
