$NetBSD: patch-intern_itasc_kdl_tree.hpp,v 1.1 2014/01/10 20:06:46 joerg Exp $

--- intern/itasc/kdl/tree.hpp.orig	2012-12-15 11:15:05.000000000 +0000
+++ intern/itasc/kdl/tree.hpp
@@ -41,32 +41,28 @@ namespace KDL
 {
     //Forward declaration
     class TreeElement;
-#if defined(__APPLE__)
-#  if MAC_OS_X_VERSION_MIN_REQUIRED <= 1050
+#if defined(__APPLE__) && MAC_OS_X_VERSION_MIN_REQUIRED <= 1050
     typedef std::map<std::string,TreeElement> SegmentMap;
-#  else
-    // Eigen allocator is needed for alignment of Eigen data types
-    typedef std::map<std::string,TreeElement, std::less<std::string>, Eigen::aligned_allocator<std::pair<std::string, TreeElement> > > SegmentMap;
-#  endif /* MAC_OS_X_VERSION_MIN_REQUIRED */
 #else
     // Eigen allocator is needed for alignment of Eigen data types
     typedef std::map<std::string,TreeElement, std::less<std::string>, Eigen::aligned_allocator<std::pair<std::string, TreeElement> > > SegmentMap;
 #endif
+
     class TreeElement
     {
     public:
-        TreeElement():q_nr(0)
+        TreeElement():q_nr(0),parent(0)
         {};
     public:
         Segment segment;
         unsigned int q_nr;
-        SegmentMap::const_iterator  parent;
+        SegmentMap::value_type const *parent;
         std::vector<SegmentMap::const_iterator > children;
-        TreeElement(const Segment& segment_in,const SegmentMap::const_iterator& parent_in,unsigned int q_nr_in)
+        TreeElement(const Segment& segment_in,const SegmentMap::value_type& parent_in,unsigned int q_nr_in)
         {
 			q_nr=q_nr_in;
             segment=segment_in;
-            parent=parent_in;
+            parent=&parent_in;
         };
         static TreeElement Root()
         {
@@ -167,7 +163,15 @@ namespace KDL
             return segments.find(segment_name);
         };
 
+        SegmentMap::value_type const* getSegmentPtr(const std::string& segment_name)const
+        {
+            SegmentMap::const_iterator it = segments.find(segment_name);
+            
+            if (it == segments.end())
+                return 0;
 
+            return &*it;
+        };
 
         const SegmentMap& getSegments()const
         {
