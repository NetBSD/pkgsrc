$NetBSD: patch-trace.c,v 1.1 2015/05/28 07:50:33 tron Exp $

Fix build failure caused by bad definition of "wunctrl" macro under NetBSD
which has been fixed in NetBSD-current.

--- trace.c.orig	2011-10-18 11:47:26.000000000 +0100
+++ trace.c	2015-05-28 08:47:19.000000000 +0100
@@ -93,7 +93,7 @@
 			wchar_t *uc;
 
 			if (win_wch(win, &cch) == ERR
-			    || (uc = wunctrl(&cch)) == 0
+			    || (uc = wunctrl((&cch))) == 0
 			    || uc[1] != 0
 			    || wcwidth(uc[0]) <= 0) {
 			    buffer[0] = '.';
