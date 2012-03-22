$NetBSD: patch-libk3b_jobs_k3bdatatrackreader.cpp,v 1.1 2012/03/22 06:39:01 markd Exp $

--- libk3b/jobs/k3bdatatrackreader.cpp.orig	2009-04-22 05:54:02.000000000 +1200
+++ libk3b/jobs/k3bdatatrackreader.cpp
@@ -256,7 +256,11 @@ bool K3b::DataTrackReader::run()
     //
     d->device->setSpeed( 0xffff, 0xffff );
 
+#ifdef __NetBSD__
+    s_bufferSizeSectors = 31;
+#else
     s_bufferSizeSectors = 128;
+#endif
     unsigned char* buffer = new unsigned char[d->usedSectorSize*s_bufferSizeSectors];
     while( s_bufferSizeSectors > 0 && read( buffer, d->firstSector.lba(), s_bufferSizeSectors ) < 0 ) {
         kDebug() << "(K3b::DataTrackReader) determine max read sectors: "
