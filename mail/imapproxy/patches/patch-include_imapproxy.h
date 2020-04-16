$NetBSD: patch-include_imapproxy.h,v 1.3 2020/04/16 14:03:29 manu Exp $

SASL PLAIN Support. Patch submitted upstream
http://sourceforge.net/tracker/?func=detail&aid=3610674&group_id=311&atid=300311

--- include/imapproxy.h.orig	2013-04-15 11:57:37.000000000 +0200
+++ include/imapproxy.h	2013-04-15 11:58:33.000000000 +0200
@@ -311,8 +311,9 @@
     unsigned char support_unselect;           /* unselect support flag */
     unsigned char support_starttls;           /* starttls support flag */
     unsigned char login_disabled;             /* login disabled flag */
     char *chroot_directory;                   /* chroot(2) into this dir */
+    char *auth_sasl_mech;                     /* SASL mechanism */
 };
 
 
 /*
