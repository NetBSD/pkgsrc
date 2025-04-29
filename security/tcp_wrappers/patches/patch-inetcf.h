$NetBSD: patch-inetcf.h,v 1.1 2025/04/29 14:18:00 tnn Exp $

--- inetcf.h.orig	2025-04-29 13:28:22.132359019 +0000
+++ inetcf.h
@@ -4,9 +4,9 @@
   * Author: Wietse Venema, Eindhoven University of Technology, The Netherlands.
   */
 
-extern char *inet_cfg();		/* read inetd.conf file */
-extern void inet_set();			/* remember internet service */
-extern int inet_get();			/* look up internet service */
+extern char *inet_cfg(char *);		/* read inetd.conf file */
+extern void inet_set(char *, int);			/* remember internet service */
+extern int inet_get(char *);			/* look up internet service */
 
 #define WR_UNKNOWN	(-1)		/* service unknown */
 #define WR_NOT		1		/* may not be wrapped */
