$NetBSD: patch-lib_cgraph_scan.l,v 1.4.2.2 2014/12/01 22:47:13 tron Exp $

Add format string.
https://github.com/ellson/graphviz/commit/99eda421f7ddc27b14e4ac1d2126e5fe41719081

--- lib/cgraph/scan.l.orig	2014-04-13 20:40:25.000000000 +0000
+++ lib/cgraph/scan.l
@@ -149,7 +149,7 @@ static int chkNum(void) {
 	agxbput(&xb,buf);
 	agxbput(&xb,fname);
 	agxbput(&xb, " splits into two tokens\n");
-	agerr(AGWARN,agxbuse(&xb));
+	agerr(AGWARN,"%s", agxbuse(&xb));
 
 	agxbfree(&xb);
 	return 1;
