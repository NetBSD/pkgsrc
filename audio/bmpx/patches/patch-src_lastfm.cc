$NetBSD: patch-src_lastfm.cc,v 1.1 2012/11/16 20:05:35 joerg Exp $

--- src/lastfm.cc.orig	2012-11-16 15:11:53.000000000 +0000
+++ src/lastfm.cc
@@ -811,12 +811,12 @@ namespace Bmp
 
         xmlDocSetRootElement (doc, lqm);
 
-        for (LQM::size_type n = 0 ; n < m_queue.size(); ++n)
+        for (LQM::size_type n2 = 0 ; n2 < m_queue.size(); ++n2)
         {
           static boost::format uint64_f ("%llu");
           static boost::format uint_f ("%u");
 
-          TrackQueueItem const& i (m_queue[n]);
+          TrackQueueItem const& i (m_queue[n2]);
 
           xmlNodePtr n = xmlNewChild (q, bmp, BAD_CAST N_LQM_TRACK, 0);
 
