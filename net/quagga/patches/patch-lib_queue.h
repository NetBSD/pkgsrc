$NetBSD: patch-lib_queue.h,v 1.1 2013/10/21 08:57:33 fhajny Exp $

Fix build on SunOS.
--- lib/queue.h.orig	2013-07-30 14:47:01.000000000 +0000
+++ lib/queue.h
@@ -33,7 +33,9 @@
 #ifndef _SYS_QUEUE_H_
 #define	_SYS_QUEUE_H_
 
+#if !defined(__sun)
 #include <sys/cdefs.h>
+#endif
 
 /*
  * This file defines four types of data structures: singly-linked lists,
