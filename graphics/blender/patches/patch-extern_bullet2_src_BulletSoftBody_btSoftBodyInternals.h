$NetBSD: patch-extern_bullet2_src_BulletSoftBody_btSoftBodyInternals.h,v 1.1 2012/10/20 22:10:18 joerg Exp $

Some instanciations don't have a user-defined default constructor,
so make sure to use plain initialisation.

--- extern/bullet2/src/BulletSoftBody/btSoftBodyInternals.h.orig	2012-10-20 10:52:46.000000000 +0000
+++ extern/bullet2/src/BulletSoftBody/btSoftBodyInternals.h
@@ -171,7 +171,7 @@ public:
 template <typename T>
 static inline void			ZeroInitialize(T& value)
 {
-	static const T	zerodummy;
+	static T	zerodummy;
 	value=zerodummy;
 }
 //
