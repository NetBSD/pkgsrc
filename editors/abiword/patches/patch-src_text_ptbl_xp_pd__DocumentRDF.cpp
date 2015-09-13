$NetBSD: patch-src_text_ptbl_xp_pd__DocumentRDF.cpp,v 1.1 2015/09/13 21:32:13 nros Exp $

* fixes build on FreeBSD 10 with clang. From FreeBSD ports mailing list.
  Applied upstream.
  https://lists.freebsd.org/pipermail/freebsd-ports/2015-March/098621.html

--- src/text/ptbl/xp/pd_DocumentRDF.cpp.orig	2015-04-04 22:33:15.000000000 +0000
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
