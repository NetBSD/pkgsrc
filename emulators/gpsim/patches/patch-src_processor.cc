$NetBSD: patch-src_processor.cc,v 1.1 2011/12/19 15:52:21 wiz Exp $

Add missing include.
Avoid conflict with C++ list<>.

--- src/processor.cc.orig	2005-10-01 21:12:55.000000000 +0000
+++ src/processor.cc
@@ -36,6 +36,7 @@ Boston, MA 02111-1307, USA.  */
 #include <iostream>
 #include <iomanip>
 #include <string>
+#include <typeinfo>
 
 #include "../config.h"
 #include "gpsim_def.h"
@@ -628,11 +629,11 @@ void Processor::read_src_files(void)
 
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
 		     unsigned int start_line, 
 		     unsigned int end_line)
@@ -2122,7 +2123,7 @@ void FileContext::ReadSource(void)
   line_seek = new vector<int>(max_line()+1);
   pm_address = new vector<int>(max_line()+1);
 
-  std::rewind(fptr);
+  ::rewind(fptr);
 
   char buf[256],*s;
   (*line_seek)[0] = 0;
