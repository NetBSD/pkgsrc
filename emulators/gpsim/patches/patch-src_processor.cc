$NetBSD: patch-src_processor.cc,v 1.2 2013/06/11 12:58:42 ryoon Exp $

Add missing include.
Avoid conflict with C++ list<>.

--- src/processor.cc.orig	2011-02-16 06:38:31.000000000 +0000
+++ src/processor.cc
@@ -733,11 +733,11 @@ void Processor::read_src_files(void)
 
 //-------------------------------------------------------------------
 //
-// processor -- list
+// processor -- plist
 //
 // Display the contents of either a source or list file
 //
-void Processor::list(unsigned int file_id,
+void Processor::plist(unsigned int file_id,
                      unsigned int pc_val,
                      int start_line,
                      int end_line)
@@ -2346,7 +2346,7 @@ void FileContext::ReadSource(void)
   line_seek.resize(max_line()+1);
   pm_address.resize(max_line()+1);
 
-  std::rewind(fptr);
+  ::rewind(fptr);
 
   char buf[256],*s;
   line_seek[0] = 0;
