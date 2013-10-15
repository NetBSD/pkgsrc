$NetBSD: patch-async_init.h,v 1.1 2013/10/15 14:48:38 joerg Exp $

--- async/init.h.orig	2013-10-14 20:49:48.000000000 +0000
+++ async/init.h
@@ -43,7 +43,7 @@ public:
 };
 #define INITFN(fn)				\
 static void fn ();				\
-static initfn init_ ## fn (fn) __attribute__ ((unused))
+static __attribute__((used)) initfn init_ ## fn (fn)
 
 class exitfn {
   void (*const fn) ();
@@ -53,6 +53,6 @@ public:
 };
 #define EXITFN(fn)					\
 static void fn ();					\
-static exitfn exit_ ## fn (fn) __attribute__ ((unused))
+static __attribute__((used))  exitfn exit_ ## fn (fn)
 
 #endif /* !_ASYNC_INIT_H_ */
