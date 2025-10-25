$NetBSD: patch-src_FlightCrew_Framework_ValidateEpub.cpp,v 1.1 2025/10/25 13:20:08 kikadf Exp $

* Fix CVE-2019-13032 with upstream commits:
  https://github.com/Sigil-Ebook/flightcrew/commit/c75c100218ed5c0e7652947051e28b54a75212ae
  https://github.com/Sigil-Ebook/flightcrew/commit/b4f4a70f604ddcb4e8e343aa0e690764fc46d780

--- src/FlightCrew/Framework/ValidateEpub.cpp.orig	2025-10-04 12:04:47.334261964 +0000
+++ src/FlightCrew/Framework/ValidateEpub.cpp
@@ -118,10 +118,15 @@ fs::path GetRelativePathToNcx( const xc:
         std::string href       = fromX( item->getAttribute( toX( "href" )       ) );
         std::string media_type = fromX( item->getAttribute( toX( "media-type" ) ) );
 
-        if ( xc::XMLUri::isValidURI( true, toX( href ) ) &&
-             media_type == NCX_MIME )
-        {
-            return Util::Utf8PathToBoostPath( Util::UrlDecode( href ) );  
+        // prevent segfault here that would result as toX() will return null when 
+        // passed and empty string
+        if (!href.empty()) {
+
+             if ( xc::XMLUri::isValidURI( true, toX( href ) ) &&
+                  media_type == NCX_MIME )
+             {
+                 return Util::Utf8PathToBoostPath( Util::UrlDecode( href ) );  
+             }
         }
     }
 
@@ -141,10 +146,13 @@ std::vector< fs::path > GetRelativePaths
         std::string href       = fromX( item->getAttribute( toX( "href" )       ) );
         std::string media_type = fromX( item->getAttribute( toX( "media-type" ) ) );
 
-        if ( xc::XMLUri::isValidURI( true, toX( href ) ) &&
-             ( media_type == XHTML_MIME || media_type == OEB_DOC_MIME ) )
-        {                    
-            paths.push_back( Util::Utf8PathToBoostPath( Util::UrlDecode( href ) ) );
+        if (!href.empty()) {
+
+             if ( xc::XMLUri::isValidURI( true, toX( href ) ) &&
+                  ( media_type == XHTML_MIME || media_type == OEB_DOC_MIME ) )
+             {
+                  paths.push_back( Util::Utf8PathToBoostPath( Util::UrlDecode( href ) ) );
+             }
         }
     }
 
