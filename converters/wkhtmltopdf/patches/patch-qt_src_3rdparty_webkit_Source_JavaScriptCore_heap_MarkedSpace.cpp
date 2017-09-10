$NetBSD: patch-qt_src_3rdparty_webkit_Source_JavaScriptCore_heap_MarkedSpace.cpp,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/src/3rdparty/webkit/Source/JavaScriptCore/heap/MarkedSpace.cpp.orig	2016-08-23 06:13:30.000000000 +0000
+++ qt/src/3rdparty/webkit/Source/JavaScriptCore/heap/MarkedSpace.cpp
@@ -124,8 +124,8 @@ void MarkedSpace::sweep()
 size_t MarkedSpace::objectCount() const
 {
     size_t result = 0;
-    BlockIterator end = m_blocks.end();
-    for (BlockIterator it = m_blocks.begin(); it != end; ++it)
+    ConstBlockIterator end = m_blocks.end();
+    for (ConstBlockIterator it = m_blocks.begin(); it != end; ++it)
         result += (*it)->markCount();
     return result;
 }
@@ -133,8 +133,8 @@ size_t MarkedSpace::objectCount() const
 size_t MarkedSpace::size() const
 {
     size_t result = 0;
-    BlockIterator end = m_blocks.end();
-    for (BlockIterator it = m_blocks.begin(); it != end; ++it)
+    ConstBlockIterator end = m_blocks.end();
+    for (ConstBlockIterator it = m_blocks.begin(); it != end; ++it)
         result += (*it)->size();
     return result;
 }
@@ -142,8 +142,8 @@ size_t MarkedSpace::size() const
 size_t MarkedSpace::capacity() const
 {
     size_t result = 0;
-    BlockIterator end = m_blocks.end();
-    for (BlockIterator it = m_blocks.begin(); it != end; ++it)
+    ConstBlockIterator end = m_blocks.end();
+    for (ConstBlockIterator it = m_blocks.begin(); it != end; ++it)
         result += (*it)->capacity();
     return result;
 }
