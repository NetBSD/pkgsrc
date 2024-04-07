$NetBSD: patch-xim_ximtrans.cpp,v 1.1 2024/04/07 04:24:23 pho Exp $

Don't use alloca(3). It's non-standard and is easily avoidable these days.
TODO: Upstream this.

--- xim/ximtrans.cpp.orig	2024-04-07 04:14:35.459868020 +0000
+++ xim/ximtrans.cpp
@@ -42,10 +42,6 @@
 #include "xim.h"
 #include "util.h"
 
-#ifdef HAVE_ALLOCA_H
-# include <alloca.h>
-#endif
-
 // XIM Error Code
 #define XIM_BadSomething	999
 
@@ -608,7 +604,7 @@ void Connection::xim_get_im_values(RxPac
     imid = p->getC16(); // input-method id
     l = p->getC16() / 2; // number
 
-    int *ra = (int *)alloca(sizeof(int) * l);
+    int ra[l];
     int rlen = 0;
     for (i = 0; i < l; i++) {
 	ra[i] = p->getC16();
@@ -744,14 +740,13 @@ void Connection::xim_error(RxPacket *p)
 {
     C16 imid, icid, mask, ecode;
     int len;
-    char *buf;
 
     imid = p->getC16();
     icid = p->getC16();
     mask = p->getC16();
     ecode = p->getC16();
     len = p->getStrLen();
-    buf = (char *)alloca(len + 1);
+    char buf[len + 1];
     buf[len] = 0;
     p->getStr(buf);
   
