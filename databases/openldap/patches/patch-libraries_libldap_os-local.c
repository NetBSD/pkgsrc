$NetBSD: patch-libraries_libldap_os-local.c,v 1.1 2014/07/18 11:31:25 ryoon Exp $

--- libraries/libldap/os-local.c.orig	2014-01-25 13:36:15.000000000 +0000
+++ libraries/libldap/os-local.c
@@ -202,6 +202,11 @@ sendcred:
 				struct msghdr msg = {0};
 # ifdef HAVE_STRUCT_MSGHDR_MSG_CONTROL
 # ifndef CMSG_SPACE
+#  if defined(_SCO_DS)
+/* SCO OpenServer 5.0.7/3.2 has no cmsg macros. */
+#define __ALIGNBYTES		(sizeof(long) - 1)
+#define _CMSG_ALIGN(n)		(((n) + __ALIGNBYTES) & ~__ALIGNBYTES)
+#  endif
 # define CMSG_SPACE(len)	(_CMSG_ALIGN( sizeof(struct cmsghdr)) + _CMSG_ALIGN(len) )
 # endif
 # ifndef CMSG_LEN
