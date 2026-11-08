$NetBSD: patch-src_image_HeifLoader.cpp,v 1.1 2026/11/08 12:03:49 pho Exp $

std::powf() has been standardized as of C++11, but libstdc++ from GCC still
doesn't support it. Use std::pow() instead, as it's equivalent to
std::powf() in this context.

--- src/image/HeifLoader.cpp.orig	2026-11-08 11:59:07.278240553 +0000
+++ src/image/HeifLoader.cpp
@@ -28,8 +28,8 @@ static float Pq( float N, float NominalL
     constexpr float c2 = 18.8515625f;
     constexpr float c3 = 18.6875f;
 
-    const auto Nm2 = std::powf( std::max( N, 0.f ), m2inv );
-    return 10000.f * std::powf( std::max( 0.f, Nm2 - c1 ) / ( c2 - c3 * Nm2 ), m1inv ) * NominalLuminanceMul;
+    const auto Nm2 = std::pow( std::max( N, 0.f ), m2inv );
+    return 10000.f * std::pow( std::max( 0.f, Nm2 - c1 ) / ( c2 - c3 * Nm2 ), m1inv ) * NominalLuminanceMul;
 }
 
 static float Hlg( float E )
@@ -673,7 +673,7 @@ bool HeifLoader::SetupDecode( bool hdr, 
                 }
                 else
                 {
-                    *dst++ = std::powf( ( v + 0.099f ) / 1.099f, 1.f / 0.45f );
+                    *dst++ = std::pow( ( v + 0.099f ) / 1.099f, 1.f / 0.45f );
                 }
             }
             src += stride - w;
