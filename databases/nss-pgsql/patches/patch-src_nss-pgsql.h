# $NetBSD: patch-src_nss-pgsql.h,v 1.1.1.1 2013/03/17 14:12:02 asau Exp $

Adds checks for header files

--- src/nss-pgsql.h.orig	2006-01-09 22:33:07.000000000 +0000
+++ src/nss-pgsql.h
@@ -11,11 +11,15 @@
 
 #  ifdef HAVE_NSS_H
 #    include <nss.h>
+#  elsif HAVE_NSSWITCH_H
+#    include <nsswitch.h>
 #  endif
 
 #  include <pwd.h>
 #  include <grp.h>
-#  include <shadow.h>
+#  ifdef HAVE_SHADOW_H
+#    include <shadow.h>
+#  endif
 #  include <sys/types.h>
 
 #define CFGFILE SYSCONFDIR"/nss-pgsql.conf"
@@ -71,6 +75,7 @@ size_t backend_initgroups_dyn(const char
 										long int limit,
 										int *errnop);
 
+#ifdef HAVE_SHADOW_H
 enum nss_status backend_getspent(struct spwd *result,
 											char *buffer,
 											size_t buflen,
@@ -82,6 +87,7 @@ enum nss_status backend_getspnam(const c
 											size_t buflen,
 											int *errnop);
 
+#endif
 void print_err(const char *msg, ...);
 void print_msg(const char *msg, ...);
 
