$NetBSD: patch-src_BulletSoftBody_btSoftBodyInternals.h,v 1.1 2012/10/20 22:07:40 joerg Exp $

--- src/BulletSoftBody/btSoftBodyInternals.h.orig	2012-10-20 12:13:07.000000000 +0000
+++ src/BulletSoftBody/btSoftBodyInternals.h
@@ -172,7 +172,7 @@ public:
 template <typename T>
 static inline void			ZeroInitialize(T& value)
 {
-	static const T	zerodummy;
+	static T	zerodummy;
 	value=zerodummy;
 }
 //
