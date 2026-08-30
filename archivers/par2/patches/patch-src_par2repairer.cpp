$NetBSD: patch-src_par2repairer.cpp,v 1.1 2026/08/30 01:13:18 gdt Exp $

Apparently, gcc<=10, when using ostringstream, somehow turns the type
into ostream after <<, and ostream has no str().

Not yet filed upstream, because probably upstream does not regard gcc
10 as reasonable, or they would have CI with it.

--- src/par2repairer.cpp.orig	2026-08-30 01:03:00.454241587 +0000
+++ src/par2repairer.cpp
@@ -1673,9 +1673,12 @@ bool Par2Repairer::ScanDataFile(DiskFile
     {
       if (lastmatchoffset < filechecksummer.Offset() && noiselevel > nlNormal)
       {
-        progress.PrintLine((std::ostringstream()
-          << "No data found between offset " << lastmatchoffset
-          << " and " << filechecksummer.Offset()).str());
+	// Avoid gcc <= 10 bug.
+	std::ostringstream oss = std::ostringstream();
+	oss << "No data found between offset " << lastmatchoffset
+	    << " and " << filechecksummer.Offset();
+
+        progress.PrintLine(oss.str());
       }
 
       // Is this the first match
@@ -1805,9 +1808,12 @@ bool Par2Repairer::ScanDataFile(DiskFile
 
   if (lastmatchoffset < filechecksummer.Offset() && noiselevel > nlNormal)
   {
-    progress.PrintLine((std::ostringstream()
-      << "No data found between offset " << lastmatchoffset
-      << " and " << filechecksummer.Offset()).str());
+    // Avoid gcc <= 10 bug.
+    std::ostringstream oss = std::ostringstream();
+    oss << "No data found between offset " << lastmatchoffset
+	<< " and " << filechecksummer.Offset();
+
+    progress.PrintLine(oss.str());
   }
 
   // Get the Full and 16k hash values of the file
