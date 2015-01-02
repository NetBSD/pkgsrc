$NetBSD: patch-scheduler_auth.c,v 1.4 2015/01/02 02:03:42 christos Exp $

Don't pull in sys/ucred.h on Solaris as it results in procfs.h being
included and conflicts between _FILE_OFFSET_BITS=64 and 32-bit procfs.

OpenBSD defines SO_PEERCRED, but it is different from Linux's one.

--- scheduler/auth.c.orig	2014-08-28 11:37:22.000000000 -0400
+++ scheduler/auth.c	2014-12-24 14:17:35.000000000 -0500
@@ -49,7 +49,7 @@
 #ifdef HAVE_SYS_PARAM_H
 #  include <sys/param.h>
 #endif /* HAVE_SYS_PARAM_H */
-#ifdef HAVE_SYS_UCRED_H
+#if defined(HAVE_SYS_UCRED_H) && !defined(__sun) && !defined(__OpenBSD__)
 #  include <sys/ucred.h>
 typedef struct xucred cupsd_ucred_t;
 #  define CUPSD_UCRED_UID(c) (c).cr_uid
@@ -435,7 +435,7 @@
     con->type = CUPSD_AUTH_BASIC;
   }
 #endif /* HAVE_AUTHORIZATION_H */
-#if defined(SO_PEERCRED) && defined(AF_LOCAL)
+#if defined(SO_PEERCRED) && defined(AF_LOCAL) && !defined(__OpenBSD__)
   else if (!strncmp(authorization, "PeerCred ", 9) &&
            con->http->hostaddr->addr.sa_family == AF_LOCAL && con->best)
   {
@@ -940,7 +940,7 @@
 
     gss_delete_sec_context(&minor_status, &context, GSS_C_NO_BUFFER);
 
-#  if defined(SO_PEERCRED) && defined(AF_LOCAL)
+#  if defined(SO_PEERCRED) && defined(AF_LOCAL) && !defined(__OpenBSD__)
    /*
     * Get the client's UID if we are printing locally - that allows a backend
     * to run as the correct user to get Kerberos credentials of its own.
