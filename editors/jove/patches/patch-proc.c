$NetBSD: patch-proc.c,v 1.2 2023/12/19 01:00:27 gutteridge Exp $

Don't smash the stack by using the same variable for input and output.

--- proc.c	2015-10-15 14:12:25.000000000 -0400
+++ proc.c	2019-09-06 10:20:35.710848362 -0400
@@ -330,18 +330,19 @@
 char	*command;
 {
 	static char	bnm[FILESIZE];
-	register char	*cp = bnm,
+	char nm[FILESIZE];
+	char	*cp = nm,
 			c;
 
 	do {
 		c = *command++;
 	} while (jiswhite(c));
-	while (cp < &bnm[sizeof(bnm) - 1] && c != '\0' && !jiswhite(c)) {
+	while (cp < &nm[sizeof(nm) - 1] && c != '\0' && !jiswhite(c)) {
 		*cp++ = c;
 		c = *command++;
 	}
 	*cp = '\0';
-	strcpy(bnm, jbasename(bnm));
+	strcpy(bnm, jbasename(nm));
 
 	return bnm;
 }
