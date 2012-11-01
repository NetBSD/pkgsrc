$NetBSD: patch-wmgeneral_list.h,v 1.1 2012/11/01 19:52:47 joerg Exp $

--- wmgeneral/list.h.orig	2012-10-30 21:17:53.000000000 +0000
+++ wmgeneral/list.h
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
