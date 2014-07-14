$NetBSD: patch-kbruch_src_taskview.cpp,v 1.1 2014/07/14 09:35:47 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous"

--- kbruch/src/taskview.cpp.orig	2006-03-17 10:10:18.000000000 +0000
+++ kbruch/src/taskview.cpp
@@ -196,8 +196,8 @@ void TaskView::setTaskParameters(bool pa
 		pnr_ratios = 5;
 
 	// the main denominator must be at least 2^pnr_ratios
-	if (pow(2, pnr_ratios) > pmax_md)
-		pmax_md = (unsigned int) pow(2, pnr_ratios);
+	if (pow((float)2, (float)pnr_ratios) > pmax_md)
+		pmax_md = (unsigned int) pow((float)2, (float)pnr_ratios);
 
 	// so everything seems to be fine, lets set the internal values to the given
 	// ones
