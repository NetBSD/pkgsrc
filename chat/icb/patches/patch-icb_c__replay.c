$NetBSD: patch-icb_c__replay.c,v 1.1 2013/01/11 13:24:32 joerg Exp $

--- icb/c_replay.c.orig	2013-01-11 12:18:00.000000000 +0000
+++ icb/c_replay.c
@@ -171,6 +171,8 @@ int lines;
 	putl("[=End of review buffer=]", pl_flags);
 }
 
+static void bufparse(char *str);
+
 int bufmatch(str)
 {
 bufparse(str);
@@ -182,8 +184,7 @@ if (personalflag == -1 && buftype == BUF
 	return 0;
 return 1;
 }
-bufparse(str)
-char *str;
+static void bufparse(char *str)
 {
 	char cc;
 
