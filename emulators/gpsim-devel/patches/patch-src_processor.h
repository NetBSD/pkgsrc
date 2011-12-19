$NetBSD: patch-src_processor.h,v 1.1 2011/12/19 15:58:40 wiz Exp $

--- src/processor.h.orig	2005-08-31 14:48:19.000000000 +0000
+++ src/processor.h
@@ -544,7 +544,7 @@ public:
 
   virtual void disassemble (signed int start_address, 
 			    signed int end_address);
-  virtual void list(unsigned int file_id, 
+  virtual void plist(unsigned int file_id, 
 		    unsigned int pcval, 
 		    unsigned int start_line, 
 		    unsigned int end_line);
