$NetBSD: patch-scheduler_auth.c,v 1.1 2013/02/12 14:12:19 jperkin Exp $

Don't pull in sys/ucred.h on Solaris as it results in procfs.h being
included and conflicts between _FILE_OFFSET_BITS=64 and 32-bit procfs.

--- scheduler/auth.c.orig	2011-08-31 04:58:33.000000000 +0000
+++ scheduler/auth.c
@@ -84,7 +84,7 @@ extern const char *cssmErrorString(int e
 #ifdef HAVE_SYS_PARAM_H
 #  include <sys/param.h>
 #endif /* HAVE_SYS_PARAM_H */
-#ifdef HAVE_SYS_UCRED_H
+#if defined(HAVE_SYS_UCRED_H) && !defined(__sun)
 #  include <sys/ucred.h>
 typedef struct xucred cupsd_ucred_t;
 #  define CUPSD_UCRED_UID(c) (c).cr_uid
