$NetBSD: patch-src_cf_path.cpp,v 1.1 2012/11/07 15:24:39 joerg Exp $

The inline violates the ODR rule for Path.

--- src/cf/path.cpp.orig	2012-11-05 17:03:05.000000000 +0000
+++ src/cf/path.cpp
@@ -212,7 +212,7 @@ short Path::Find( const Unit *u, const P
 // RETURNS    : estimated cost to destination
 ////////////////////////////////////////////////////////////////////////
 
-inline unsigned short Path::ETA( const Point &p ) const {
+unsigned short Path::ETA( const Point &p ) const {
   return Distance( p, end ) * quality;
 }
 
