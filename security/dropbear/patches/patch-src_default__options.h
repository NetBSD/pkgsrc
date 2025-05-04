$NetBSD: patch-src_default__options.h,v 1.2 2025/05/04 13:17:39 nia Exp $

Fix hardcoded paths.

--- src/default_options.h.orig	2025-03-05 14:30:00.000000000 +0000
+++ src/default_options.h
@@ -23,10 +23,10 @@ IMPORTANT: Some options will require "ma
 /* Default hostkey paths - these can be specified on the command line.
  * Homedir is prepended if path begins with ~/
  */
-#define DSS_PRIV_FILENAME "/etc/dropbear/dropbear_dss_host_key"
-#define RSA_PRIV_FILENAME "/etc/dropbear/dropbear_rsa_host_key"
-#define ECDSA_PRIV_FILENAME "/etc/dropbear/dropbear_ecdsa_host_key"
-#define ED25519_PRIV_FILENAME "/etc/dropbear/dropbear_ed25519_host_key"
+#define DSS_PRIV_FILENAME "@PKG_SYSCONFDIR@/dropbear_dss_host_key"
+#define RSA_PRIV_FILENAME "@PKG_SYSCONFDIR@/dropbear_rsa_host_key"
+#define ECDSA_PRIV_FILENAME "@PKG_SYSCONFDIR@/dropbear_ecdsa_host_key"
+#define ED25519_PRIV_FILENAME "@PKG_SYSCONFDIR@/dropbear_ed25519_host_key"
 
 /* Set NON_INETD_MODE if you require daemon functionality (ie Dropbear listens
  * on chosen ports and keeps accepting connections. This is the default.
@@ -330,7 +330,7 @@ group1 in Dropbear server too */
 
 /* This is used by the scp binary when used as a client binary. If you're
  * not using the Dropbear client, you'll need to change it */
-#define DROPBEAR_PATH_SSH_PROGRAM "/usr/bin/dbclient"
+#define DROPBEAR_PATH_SSH_PROGRAM "@PREFIX@/bin/dbclient"
 
 /* Whether to log commands executed by a client. This only logs the
  * (single) command sent to the server, not what a user did in a
