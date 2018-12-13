$NetBSD: patch-src_input_r__matroska.cpp,v 1.1 2018/12/13 19:52:14 adam Exp $

Fix for boost-1.69.0.

--- src/input/r_matroska.cpp.orig	2018-12-13 12:11:12.000000000 +0000
+++ src/input/r_matroska.cpp
@@ -1684,7 +1684,7 @@ kax_reader_c::set_packetizer_headers(kax
     PTZR(t->ptzr)->set_track_forced_flag(true);
 
   if (boost::logic::indeterminate(PTZR(t->ptzr)->m_ti.m_enabled_track))
-    PTZR(t->ptzr)->set_track_enabled_flag(t->enabled_track);
+    PTZR(t->ptzr)->set_track_enabled_flag(t->enabled_track ? true : false);
 
   if ((0 != t->track_uid) && !PTZR(t->ptzr)->set_uid(t->track_uid))
     mxwarn(fmt::format(Y("matroska_reader: Could not keep the track UID {0} because it is already allocated for the new file.\n"), t->track_uid));
