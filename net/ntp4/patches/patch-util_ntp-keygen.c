$NetBSD: patch-util_ntp-keygen.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- util/ntp-keygen.c.orig	2020-03-04 01:38:15.000000000 +0000
+++ util/ntp-keygen.c
@@ -275,17 +275,19 @@ followlink(
 	)
 {
 	int len;
+	char result[2048];
 
 	REQUIRE(bufsiz > 0);
 
-	len = readlink(fname, fname, (int)bufsiz);
-	if (len < 0 ) {
+	len = readlink(fname, result, sizeof(result));
+	if (len < 0) {
 		fname[0] = '\0';
 		return;
 	}
 	if (len > (int)bufsiz - 1)
 		len = (int)bufsiz - 1;
-	fname[len] = '\0';
+	result[len] = '\0';
+	strcpy(fname, result);
 }
 
 
