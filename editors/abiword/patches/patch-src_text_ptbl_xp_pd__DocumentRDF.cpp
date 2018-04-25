$NetBSD: patch-src_text_ptbl_xp_pd__DocumentRDF.cpp,v 1.2 2018/04/25 05:53:53 markd Exp $

* fixes build on FreeBSD 10 with clang. From FreeBSD ports mailing list.
  Applied upstream.
  https://lists.freebsd.org/pipermail/freebsd-ports/2015-March/098621.html

* fix using modern libical

--- src/text/ptbl/xp/pd_DocumentRDF.cpp.orig	2014-02-27 05:11:32.000000000 +0000
+++ src/text/ptbl/xp/pd_DocumentRDF.cpp
@@ -570,6 +570,11 @@ bool PD_URI::operator==(const std::strin
     return m_value == b;
 }
 
+bool PD_URI::operator<(const PD_URI& b) const
+{
+return m_value < b.m_value;
+}
+
 PD_URI
 PD_URI::prefixedToURI( PD_RDFModelHandle model ) const
 {
@@ -611,11 +616,6 @@ bool PD_URI::write( std::ostream& ss ) c
     return true;
 }
 
-bool operator<( PD_URI a, PD_URI b)
-{
-    return a.toString() < b.toString();
-}
-
 bool operator<( std::pair< PD_URI, PD_URI > a, PD_URI b)
 {
     return a.first.toString() < b.toString();
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
