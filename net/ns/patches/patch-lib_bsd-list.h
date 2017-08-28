$NetBSD: patch-lib_bsd-list.h,v 1.1 2017/08/28 10:29:41 he Exp $

Actually, lib/bsd-list.h isn't a substitute for <sys/queue.h>
because TAILQ_* macros are not defined here, and on NetBSD, <net/if.h>
requires those macros be defined.

--- lib/bsd-list.h.orig	2008-03-25 04:28:30.000000000 +0000
+++ lib/bsd-list.h
@@ -40,7 +40,11 @@
 #define	_NS_BSD_LIST_H_
 
 // define _SYS_QUEUE_H_ so /usr/include/sys/queue.h does not redefine
-#define _SYS_QUEUE_H_
+#ifndef __NetBSD__
+# define _SYS_QUEUE_H_
+#endif
+// This doesn't define the 5 queue forms, and NetBSD's <net/if.h>
+// requires TAILQ_* which isn't defined here.
 
 /*
  * This file defines five types of data structures: singly-linked lists,
