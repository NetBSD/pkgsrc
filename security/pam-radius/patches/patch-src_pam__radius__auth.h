$NetBSD: patch-src_pam__radius__auth.h,v 1.1 2015/09/26 20:58:06 bsiegert Exp $

--- src/pam_radius_auth.h.orig	2014-12-17 22:00:59.000000000 +0000
+++ src/pam_radius_auth.h
@@ -83,7 +83,7 @@ typedef struct radius_conf_t {
  *************************************************************************/
 
 #ifndef CONST
-#  if defined(__sun) || defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__)
+#  if defined(__sun) || defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__)
 /*
  *  On older versions of Solaris, you may have to change this to:
  *  #define CONST
