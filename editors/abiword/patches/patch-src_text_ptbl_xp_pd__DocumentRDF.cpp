$NetBSD: patch-src_text_ptbl_xp_pd__DocumentRDF.cpp,v 1.3 2018/11/24 19:14:09 nia Exp $

fix using modern libical

--- src/text/ptbl/xp/pd_DocumentRDF.cpp.orig	2015-04-02 03:09:20.000000000 +0000
+++ src/text/ptbl/xp/pd_DocumentRDF.cpp
@@ -2269,8 +2269,8 @@ PD_RDFEvent::exportToFile( const std::st
         icalcomponent_set_uid( c,         m_uid.c_str() );
         icalcomponent_set_location( c,    m_location.c_str() );
         icalcomponent_set_description( c, m_desc.c_str() );
-        icalcomponent_set_dtstart( c,     icaltime_from_timet( m_dtstart, 0 ) );
-        icalcomponent_set_dtend( c,       icaltime_from_timet( m_dtend, 0 ) );
+        icalcomponent_set_dtstart( c,     icaltime_from_timet_with_zone( m_dtstart, 0, 0 ) );
+        icalcomponent_set_dtend( c,       icaltime_from_timet_with_zone( m_dtend, 0, 0 ) );
 
         char* data = icalcomponent_as_ical_string( c );
         std::ofstream oss( filename.c_str() );
