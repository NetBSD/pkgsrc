$NetBSD: patch-dlcommon.h,v 1.1 2013/03/30 22:28:55 tron Exp $

Fix build problem under Solaris.

--- dlcommon.h.orig	Sat Jun  7 00:42:34 2003
+++ dlcommon.h	Sat Mar 30 23:23:44 2013
@@ -32,6 +32,5 @@
 /*
  * externs go here
  */
-extern	void	sigalrm();
 
 #endif /* !DLCOMMON_H */
