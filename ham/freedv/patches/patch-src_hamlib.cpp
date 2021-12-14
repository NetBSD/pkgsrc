$NetBSD: patch-src_hamlib.cpp,v 1.1 2021/12/14 23:56:56 gdt Exp $

Fix semi-obvious use of wrong constant.  Perhaps hamlib has prefixed the
constant to avoid collisions, since this freedv release.  Not reported
upstream because the package is not up to date.
 
--- src/hamlib.cpp.orig	2020-07-18 23:16:05.000000000 +0000
+++ src/hamlib.cpp
@@ -114,7 +114,7 @@ bool Hamlib::connect(unsigned int rig_in
 
     /* TODO we may also need civaddr for Icom */
 
-    strncpy(m_rig->state.rigport.pathname, serial_port, FILPATHLEN - 1);
+    strncpy(m_rig->state.rigport.pathname, serial_port, HAMLIB_FILPATHLEN - 1);
     if (serial_rate) {
         fprintf(stderr, "hamlib: setting serial rate: %d\n", serial_rate);
         m_rig->state.rigport.parm.serial.rate = serial_rate;
