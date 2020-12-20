$NetBSD: patch-src_mp4atom.cpp,v 1.1 2020/12/20 13:07:58 nia Exp $

Fix building C applications.

Reverts the following commit:
https://github.com/TechSmith/mp4v2/commit/263719465a1c1fbe6d240b8d154da71003ce3230
https://github.com/TechSmith/mp4v2/issues/47

--- src/mp4atom.cpp.orig	2020-12-07 23:16:32.000000000 +0000
+++ src/mp4atom.cpp
@@ -237,7 +237,7 @@ void MP4Atom::Read()
 
     // skip parsing of certain atoms
     ShouldParseAtomCallback cb = m_File.GetShouldParseAtomCallback();
-    if ( cb == nullptr || cb( ATOMID(m_type) ) )
+    if ( cb == nullptr || ( cb != nullptr && cb( ATOMID(m_type) ) ) )
     {
        ReadProperties();
 
