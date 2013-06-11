$NetBSD: patch-src_processor.h,v 1.2 2013/06/11 12:58:42 ryoon Exp $

Avoid conflict with C++ list<>.

--- src/processor.h.orig	2011-03-12 09:34:27.000000000 +0000
+++ src/processor.h
@@ -581,7 +581,7 @@ public:
 
   virtual void disassemble (signed int start_address, 
                             signed int end_address);
-  virtual void list(unsigned int file_id, 
+  virtual void plist(unsigned int file_id, 
                     unsigned int pcval, 
                     int start_line, 
                     int end_line);
