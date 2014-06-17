$NetBSD: patch-scheduler_auth.c,v 1.1 2014/06/17 13:17:13 wiz Exp $

Don't pull in sys/ucred.h on Solaris as it results in procfs.h being
included and conflicts between _FILE_OFFSET_BITS=64 and 32-bit procfs.

OpenBSD defines SO_PEERCRED, but it is different from Linux's one.

--- scheduler/auth.c.orig	2011-08-31 04:58:33.000000000 +0000
+++ scheduler/auth.c
@@ -84,7 +84,7 @@ extern const char *cssmErrorString(int e
 #ifdef HAVE_SYS_PARAM_H
 #  include <sys/param.h>
 #endif /* HAVE_SYS_PARAM_H */
-#ifdef HAVE_SYS_UCRED_H
+#if defined(HAVE_SYS_UCRED_H) && !defined(__sun) && !defined(__OpenBSD__)
 #  include <sys/ucred.h>
 typedef struct xucred cupsd_ucred_t;
 #  define CUPSD_UCRED_UID(c) (c).cr_uid
@@ -493,7 +493,7 @@ cupsdAuthorize(cupsd_client_t *con)	/* I
     con->type = CUPSD_AUTH_BASIC;
   }
 #endif /* HAVE_AUTHORIZATION_H */
-#if defined(SO_PEERCRED) && defined(AF_LOCAL)
+#if defined(SO_PEERCRED) && defined(AF_LOCAL) && !defined(__OpenBSD__)
   else if (!strncmp(authorization, "PeerCred ", 9) &&
            con->http.hostaddr->addr.sa_family == AF_LOCAL)
   {
@@ -1120,7 +1120,7 @@ cupsdAuthorize(cupsd_client_t *con)	/* I
 
     gss_delete_sec_context(&minor_status, &context, GSS_C_NO_BUFFER);
 
-#  if defined(SO_PEERCRED) && defined(AF_LOCAL)
+#  if defined(SO_PEERCRED) && defined(AF_LOCAL) && !defined(__OpenBSD__)
    /*
     * Get the client's UID if we are printing locally - that allows a backend
     * to run as the correct user to get Kerberos credentials of its own.
