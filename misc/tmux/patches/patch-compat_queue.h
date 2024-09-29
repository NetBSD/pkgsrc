$NetBSD: patch-compat_queue.h,v 1.2 2024/09/29 16:18:05 schmonz Exp $

Fix build with xcode 16 and 4.2.

--- compat/queue.h.orig	2022-04-25 08:25:13.000000000 +0000
+++ compat/queue.h
@@ -32,6 +32,27 @@
  *	@(#)queue.h	8.5 (Berkeley) 8/20/94
  */
 
+#ifndef __has_include
+#define __has_include(x) 0
+#endif
+
+#if defined(__APPLE__)
+#  if __has_include(<sys/queue.h>)
+#    include <sys/queue.h>
+#    if !defined(TAILQ_REPLACE)
+#define TAILQ_REPLACE(head, elm, elm2, field) do {			\
+	if (((elm2)->field.tqe_next = (elm)->field.tqe_next) != NULL)	\
+		(elm2)->field.tqe_next->field.tqe_prev =		\
+		    &(elm2)->field.tqe_next;				\
+	else								\
+		(head)->tqh_last = &(elm2)->field.tqe_next;		\
+	(elm2)->field.tqe_prev = (elm)->field.tqe_prev;			\
+	*(elm2)->field.tqe_prev = (elm2);				\
+} while (0)
+#    endif
+#  endif
+#endif
+
 #ifndef	_SYS_QUEUE_H_
 #define	_SYS_QUEUE_H_
 
