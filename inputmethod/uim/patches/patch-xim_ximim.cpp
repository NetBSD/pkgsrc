$NetBSD: patch-xim_ximim.cpp,v 1.1 2024/04/07 04:24:23 pho Exp $

Don't use alloca(3). It's non-standard and is easily avoidable these days.
TODO: Upstream this.

--- xim/ximim.cpp.orig	2024-04-07 04:15:45.715921186 +0000
+++ xim/ximim.cpp
@@ -46,10 +46,6 @@
 #define NEED_EVENTS	// for declaration of xEvent
 #include <X11/Xproto.h>
 
-#ifdef HAVE_ALLOCA_H
-# include <alloca.h>
-#endif
-
 static std::map<C16, XimIM *> g_ims;
 
 // tables
@@ -174,8 +170,7 @@ void XimIM_impl::set_ic_values(RxPacket 
     atr_len = p->getC16();
     p->getC16();
 
-    unsigned char *v;
-    v = (unsigned char *)alloca(atr_len);
+    unsigned char v[atr_len];
 
     int i;
     for (i = 0; i < atr_len; i++) {
