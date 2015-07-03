$NetBSD: patch-src_ntp.c,v 1.1 2015/07/03 12:31:12 wiz Exp $

Abort if configuration specifies tls constraints and ntpd not compiled with
tls support; accepted upstream.

--- src/ntp.c.orig	2015-03-12 02:15:36.000000000 +0000
+++ src/ntp.c
@@ -110,12 +110,14 @@ ntp_main(int pipe_prnt[2], int fd_ctl, s
 		return (pid);
 	}
 
+#ifdef HAVE_LIBTLS
 	tls_init();
 
 	/* Verification will be turned off if CA is not found */
 	if ((conf->ca = tls_load_file(CONSTRAINT_CA,
 	    &conf->ca_len, NULL)) == NULL)
 		log_warnx("constraint certificate verification turned off");
+#endif
 
 	/* in this case the parent didn't init logging and didn't daemonize */
 	if (nconf->settime && !nconf->debug) {
