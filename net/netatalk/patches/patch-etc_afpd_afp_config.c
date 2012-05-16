$NetBSD: patch-etc_afpd_afp_config.c,v 1.1 2012/05/16 14:03:08 hauke Exp $

Avoid a SIGSEGV when AFPConfigInit() runs into a problem and returns NULL.

--- etc/afpd/afp_config.c.orig	2011-07-22 04:30:42.000000000 +0000
+++ etc/afpd/afp_config.c
@@ -591,7 +591,7 @@ AFPConfig *configinit(struct afp_options
         first = AFPConfigInit(cmdline, cmdline);
 
     /* Now register with zeroconf, we also need the volumes for that */
-    if (! (first->obj.options.flags & OPTION_NOZEROCONF)) {
+    if (first != NULL && ! (first->obj.options.flags & OPTION_NOZEROCONF)) {
         load_volumes(&first->obj);
         zeroconf_register(first);
     }
