$NetBSD: patch-src-afs-NBSD-osi_machdep.h,v 1.1 2013/01/07 00:03:43 christos Exp $

--- src/afs/NBSD/osi_machdep.h.orig	2012-04-22 23:40:23.000000000 -0400
+++ src/afs/NBSD/osi_machdep.h	2013-01-06 17:12:00.000000000 -0500
@@ -52,7 +52,7 @@
 #define v_vfsp		v_mount
 
 /* vnode */
-#define VN_HOLD(vp)	(vget(vp, 0))
+#define VN_HOLD(vp)	(mutex_enter((vp)->v_interlock), vget((vp), 0))
 #define VN_RELE(vp)	(vrele(vp))
 #define osi_vnhold(avc, r) (VN_HOLD(AFSTOV(avc)))
 
