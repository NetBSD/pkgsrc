$NetBSD: patch-ResultTable.cc,v 1.2 2025/01/27 14:12:17 wiz Exp $

Fix "abs(int) is ambigous" on SunOS

--- ResultTable.cc.orig	2005-02-12 20:32:18.000000000 +0000
+++ ResultTable.cc
@@ -909,11 +909,11 @@ void ResultTable::lmsint(double &a, doub
 	l = 0;
 	for (i = 0; i < columns; i++) {
 	    if (partialmins[i] != timeoutresult) {
-		residuals[l] = abs(partialmins[i] - 
+		residuals[l] = abs((double)(partialmins[i] - 
 				   ((currentslope * 
 				     column2size(i) /
 				     slopescale) +
-				    currentintercept));
+				    currentintercept)));
 		ys[l] = partialmins[i];
 		
 		l++;
@@ -930,7 +930,7 @@ void ResultTable::lmsint(double &a, doub
 	l = 0;
 	for (i = 0; i < columns; i++) {
 	    if (partialmins[i] != timeoutresult) {
-		ys[l] = abs(partialmins[i] - mediany);
+		ys[l] = abs((double)(partialmins[i] - mediany));
 		l++;
 	    }
 	}
