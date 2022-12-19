$NetBSD: patch-etsh.c,v 1.1 2022/12/19 11:13:56 vins Exp $

Define NSIG on Linux.

--- etsh.c.orig	2019-03-17 18:01:40.000000000 +0000
+++ etsh.c
@@ -150,10 +150,9 @@
 #define	FD_ISREG	S_IFREG	/* Does FD refer to a  regular file?          */
 
 /*
- * Needed by OpenIndiana
  * (NSIG - 1) is the maximum signal number value accepted by `trap'.
  */
-#ifdef	CONFIG_SUNOS
+#if defined(CONFIG_SUNOS) || defined(CONFIG_LINUX)
 #ifndef	NSIG
 #define	NSIG	33
 #endif
