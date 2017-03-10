$NetBSD: patch-waftools_checks_custom.py,v 1.1 2017/03/10 15:55:33 nat Exp $

Pkgconfig descriptions are not available for rpi_userland on NetBSD.

--- waftools/checks/custom.py.orig	2017-03-10 15:24:39.000000000 +0000
+++ waftools/checks/custom.py
@@ -142,9 +142,6 @@ def check_rpi(ctx, dependency_identifier
                       prev_pkg_path]))
 
     checks = [
-        check_pkg_config('bcm_host', uselib_store='bcm_host'),
-        check_pkg_config('egl'),
-        check_pkg_config('glesv2'),
         check_cc(lib=['mmal_core', 'mmal_util', 'mmal_vc_client'], use=['bcm_host']),
         # We still need all OpenGL symbols, because the vo_opengl code is
         # generic and supports anything from GLES2/OpenGL 2.1 to OpenGL 4 core.
