$NetBSD: patch-image.h,v 1.1 2021/04/04 09:09:30 nia Exp $

Avoid conflicting with NetBSD libc.

--- image.h.orig	2020-04-29 19:47:42.000000000 +0000
+++ image.h
@@ -20,7 +20,7 @@ extern "C" {
  * \brief 	Image manipulation functions
  */
 
-static inline Uint32 popcount(const Uint32 x)
+static inline Uint32 el_popcount(const Uint32 x)
 {
 	Uint32 r;
 
@@ -29,6 +29,8 @@ static inline Uint32 popcount(const Uint
 	return ((r + (r >> 3)) & 030707070707) % 63;
 }
 
+#define popcount el_popcount
+
 /*!
  * \ingroup 	textures
  * \brief 	Unpacks the given image
