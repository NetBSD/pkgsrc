$NetBSD: patch-scheduler_auth.c,v 1.6 2026/04/19 14:52:23 wiz Exp $

- Don't pull in sys/ucred.h on Solaris as it results in procfs.h being
  included and conflicts between _FILE_OFFSET_BITS=64 and 32-bit procfs.
- OpenBSD defines SO_PEERCRED, but it is different from Linux's one.

--- scheduler/auth.c.orig	2026-04-17 12:22:45.000000000 +0000
+++ scheduler/auth.c
@@ -40,7 +40,7 @@
 #ifdef HAVE_SYS_PARAM_H
 #  include <sys/param.h>
 #endif /* HAVE_SYS_PARAM_H */
-#ifdef HAVE_SYS_UCRED_H
+#if defined(HAVE_SYS_UCRED_H) && !defined(__sun) && !defined(__OpenBSD__)
 #  include <sys/ucred.h>
 typedef struct xucred cupsd_ucred_t;
 #  define CUPSD_UCRED_UID(c) (c).cr_uid
@@ -397,7 +397,7 @@ cupsdAuthorize(cupsd_client_t *con)	/* I - Client conn
     con->type = CUPSD_AUTH_BASIC;
   }
 #endif /* HAVE_AUTHORIZATION_H */
-#if defined(SO_PEERCRED) && defined(AF_LOCAL)
+#if defined(SO_PEERCRED) && defined(AF_LOCAL) && !defined(__OpenBSD__)
   else if (PeerCred != CUPSD_PEERCRED_OFF && !strncmp(authorization, "PeerCred ", 9) &&
            httpAddrFamily(httpGetAddress(con->http)) == AF_LOCAL && con->best)
   {
@@ -852,7 +852,7 @@ cupsdAuthorize(cupsd_client_t *con)	/* I - Client conn
 
     gss_delete_sec_context(&minor_status, &context, GSS_C_NO_BUFFER);
 
-#  if defined(SO_PEERCRED) && defined(AF_LOCAL)
+#  if defined(SO_PEERCRED) && defined(AF_LOCAL) && !defined(__OpenBSD__)
    /*
     * Get the client's UID if we are printing locally - that allows a backend
     * to run as the correct user to get Kerberos credentials of its own.
