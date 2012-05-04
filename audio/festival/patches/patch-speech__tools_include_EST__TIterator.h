$NetBSD: patch-speech__tools_include_EST__TIterator.h,v 1.1 2012/05/04 16:01:04 joerg Exp $

--- speech_tools/include/EST_TIterator.h.orig	2012-04-27 12:26:17.000000000 +0000
+++ speech_tools/include/EST_TIterator.h
@@ -209,7 +209,7 @@ public:  
 
   /// Create an iterator ready to run over the given container.
   EST_TStructIterator(const Container &over)
-    { begin(over); }
+    { this->begin(over); }
 
   const Entry *operator ->() const
     {return &this->current();}
@@ -289,7 +289,7 @@ public:
 
   /// Create an iterator ready to run over the given container.
   EST_TRwStructIterator(Container &over)
-    { begin(over); }
+    { this->begin(over); }
 
   Entry *operator ->() const
     {return &this->current();}
