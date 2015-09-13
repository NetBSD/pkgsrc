$NetBSD: patch-src_text_ptbl_xp_pd__DocumentRDF.h,v 1.1 2015/09/13 21:32:13 nros Exp $
* Fixes build on FreeBSD 10 with clang. From freebsd-ports mailing list.
  Applied upstream.
  https://lists.freebsd.org/pipermail/freebsd-ports/2015-March/098621.html

--- src/text/ptbl/xp/pd_DocumentRDF.h.orig	2015-04-04 22:38:01.000000000 +0000
+++ src/text/ptbl/xp/pd_DocumentRDF.h
@@ -68,6 +68,7 @@ class ABI_EXPORT PD_URI
     bool isValid() const;
     bool operator==(const PD_URI& b) const;
     bool operator==(const std::string& b) const;
+    bool operator<(const PD_URI& b) const;
 
     virtual bool read( std::istream& ss );
     virtual bool write( std::ostream& ss ) const;
