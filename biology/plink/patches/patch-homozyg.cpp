$NetBSD: patch-homozyg.cpp,v 1.1 2026/01/03 11:45:59 wiz Exp $

Fix
error: static assertion failed: comparison object must be invocable as const 

--- homozyg.cpp.orig	2009-10-10 16:00:21.000000000 +0000
+++ homozyg.cpp
@@ -33,7 +33,7 @@ namespace std
   template<>
   class less<Segment*> {
   public:
-  bool operator()(Segment const* s1, Segment const* s2)
+  bool operator()(Segment const* s1, Segment const* s2) const
   {
     if      ( s1->start  > s2->start ) return true;
     else if ( s1->start  < s2->start ) return false;
@@ -70,7 +70,7 @@ namespace std
   template<>
   class less<Pool*> {
   public:
-  bool operator()(Pool const* p1, Pool const* p2)
+  bool operator()(Pool const* p1, Pool const* p2) const
   {
 
     if      ( p1->segs.size() > p2->segs.size() ) return true; 
