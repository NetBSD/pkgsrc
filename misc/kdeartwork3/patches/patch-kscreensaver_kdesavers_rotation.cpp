$NetBSD: patch-kscreensaver_kdesavers_rotation.cpp,v 1.1 2015/03/18 10:27:54 joerg Exp $

--- kscreensaver/kdesavers/rotation.cpp.orig	2015-03-17 22:45:37.000000000 +0000
+++ kscreensaver/kdesavers/rotation.cpp
@@ -123,9 +123,9 @@ std::valarray<double> EulerOdeSolver::f(
    ypr[2] = -(B-A)/C * omega_body[0] * omega_body[1]; // r'
 
    // e1', e2', e3'
-   ypr[std::slice(3,3,1)] = vec3<double>::crossprod(omega, e1);
-   ypr[std::slice(6,3,1)] = vec3<double>::crossprod(omega, e2);
-   ypr[std::slice(9,3,1)] = vec3<double>::crossprod(omega, e3);
+   ypr[std::slice(3,3,1)] = std::valarray<double>(vec3<double>::crossprod(omega, e1));
+   ypr[std::slice(6,3,1)] = std::valarray<double>(vec3<double>::crossprod(omega, e2));
+   ypr[std::slice(9,3,1)] = std::valarray<double>(vec3<double>::crossprod(omega, e3));
 
    return ypr;
 }
@@ -529,15 +529,17 @@ void KRotationSaver::initData()
    e3_body.rotate(-m_initEulerTheta*e1_body);
    // omega_body = L_body * J_body^(-1)
    vec3<double> omega_body = e3_body * m_Lz;
-   omega_body /= J;
+   std::valarray<double> &omega_body_ = omega_body;
+   std::valarray<double> &J_ = J;
+   omega_body_ /= J_;
 
    // assemble initial y for solver
    std::valarray<double> y(12);
-   y[std::slice(0,3,1)] = omega_body;
+   y[std::slice(0,3,1)] = std::valarray<double>(omega_body);
    // 3 basis vectors of body system in fixed coordinates
-   y[std::slice(3,3,1)] = e1t;
-   y[std::slice(6,3,1)] = e2t;
-   y[std::slice(9,3,1)] = e3t;
+   y[std::slice(3,3,1)] = std::valarray<double>(e1t);
+   y[std::slice(6,3,1)] = std::valarray<double>(e2t);
+   y[std::slice(9,3,1)] = std::valarray<double>(e3t);
 
    // initial rotation vector
    omega
