$NetBSD: patch-src_par2repairer.cpp,v 1.2 2026/09/10 09:56:15 adam Exp $

Apparently, gcc<=10, when using ostringstream, somehow turns the type
into ostream after <<, and ostream has no str().

Not yet filed upstream, because probably upstream does not regard gcc
10 as reasonable, or they would have CI with it.

--- src/par2repairer.cpp.orig	2026-09-09 06:33:53.000000000 +0000
+++ src/par2repairer.cpp
@@ -1943,9 +1943,12 @@ bool Par2Repairer::ScanDataFile(DiskFile
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
@@ -2073,9 +2076,12 @@ bool Par2Repairer::ScanDataFile(DiskFile
 
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
 
   }
