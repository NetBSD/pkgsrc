$NetBSD: patch-src_list.h,v 1.1 2012/05/04 16:34:48 joerg Exp $

--- src/list.h.orig	2012-05-04 13:34:36.000000000 +0000
+++ src/list.h
@@ -29,11 +29,7 @@ Boston, MA 02111-1307, USA.  */
 #ifndef __LIST_H_
 #define __LIST_H_
 
-#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
-# define INLINE inline
-#else
-# define INLINE
-#endif
+#define INLINE
 
 typedef struct LinkedList {
   void *head;
