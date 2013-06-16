$NetBSD: patch-game_SelectableFactory.hpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- game/SelectableFactory.hpp.orig	2013-06-15 10:07:11.000000000 +0000
+++ game/SelectableFactory.hpp
@@ -40,7 +40,7 @@ protected:
     virtual ~SelectableFactory() {}
 
     static hash_map< 
-        const string, SelectableFactory*, hash<const string>, equal_to<const string> > _sfMap;
+        const string, SelectableFactory*, HASH_NAMESPACE::hash<const string>, equal_to<const string> > _sfMap;
 
     void posToPoint2D( const string &pos, Point2D &point);
     string getAttribute( const TiXmlElement* elem, string attr);
