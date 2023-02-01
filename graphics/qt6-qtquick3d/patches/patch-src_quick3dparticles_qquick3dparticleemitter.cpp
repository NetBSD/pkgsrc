$NetBSD: patch-src_quick3dparticles_qquick3dparticleemitter.cpp,v 1.1 2023/02/01 19:36:37 wiz Exp $

Fix
qquick3dparticleemitter.cpp:723:84: error: no matching function for call to 'min(float, __gnu_cxx::__enable_if<true, double>::__type)'

--- src/quick3dparticles/qquick3dparticleemitter.cpp.orig	2022-11-08 19:27:13.000000000 +0000
+++ src/quick3dparticles/qquick3dparticleemitter.cpp
@@ -716,11 +716,11 @@ void QQuick3DParticleEmitter::emitPartic
         // max value 127*127 = 16129 degrees/second
         float sign;
         sign = rotVelX < 0.0f ? -1.0f : 1.0f;
-        rotVelX = std::max(-127.0f, std::min(127.0f, sign * std::sqrt(abs(rotVelX))));
+        rotVelX = std::max(-127.0f, std::min<float>(127.0f, sign * std::sqrt(abs(rotVelX))));
         sign = rotVelY < 0.0f ? -1.0f : 1.0f;
-        rotVelY = std::max(-127.0f, std::min(127.0f, sign * std::sqrt(abs(rotVelY))));
+        rotVelY = std::max(-127.0f, std::min<float>(127.0f, sign * std::sqrt(abs(rotVelY))));
         sign = rotVelZ < 0.0f ? -1.0f : 1.0f;
-        rotVelZ = std::max(-127.0f, std::min(127.0f, sign * std::sqrt(abs(rotVelZ))));
+        rotVelZ = std::max(-127.0f, std::min<float>(127.0f, sign * std::sqrt(abs(rotVelZ))));
         d->startRotationVelocity = { qint8(rotVelX), qint8(rotVelY), qint8(rotVelZ) };
     }
 
