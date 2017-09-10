$NetBSD: patch-qt_src_3rdparty_webkit_Source_JavaScriptCore_heap_MarkedSpace.h,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/src/3rdparty/webkit/Source/JavaScriptCore/heap/MarkedSpace.h.orig	2016-08-23 06:13:30.000000000 +0000
+++ qt/src/3rdparty/webkit/Source/JavaScriptCore/heap/MarkedSpace.h
@@ -92,6 +92,7 @@ namespace JSC {
         static const size_t impreciseCount = impreciseCutoff / impreciseStep - 1;
 
         typedef HashSet<MarkedBlock*>::iterator BlockIterator;
+        typedef HashSet<MarkedBlock*>::const_iterator ConstBlockIterator;
 
         struct SizeClass {
             SizeClass();
