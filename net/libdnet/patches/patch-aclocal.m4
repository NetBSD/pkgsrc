$NetBSD: patch-aclocal.m4,v 1.1 2011/02/07 05:45:17 obache Exp $

* Add support for SIOCGIFCONF interface

--- aclocal.m4.orig	2007-01-12 22:01:42.000000000 +0000
+++ aclocal.m4
@@ -6776,6 +6776,30 @@ AC_DEFUN(AC_DNET_SOCKADDR_SA_LEN,
     fi])
 
 dnl
+dnl Check for NetBSD ifreq structure
+dnl
+dnl usage:	AC_DNET_IFREQ_IFR_SPACE
+dnl results:	HAVE_IFREQ_IFR_SPACE (defined)
+dnl
+AC_DEFUN(AC_DNET_IFREQ_IFR_SPACE,
+    [AC_MSG_CHECKING(for ifr_space in ifreq struct)
+    AC_CACHE_VAL(ac_cv_dnet_ifreq_has_ifr_space,
+        AC_TRY_COMPILE([
+# ifndef _IFREQ_IFR_SPACE
+#	define _IFREQ_IFR_SPACE 1 
+# endif
+#       include <sys/types.h>
+#       include <net/if.h>],
+        [u_int i = sizeof(((struct ifreq *)0)->ifr_space)],
+        ac_cv_dnet_ifreq_has_ifr_space=yes,
+        ac_cv_dnet_ifreq_has_ifr_space=no))
+    AC_MSG_RESULT($ac_cv_dnet_ifreq_has_ifr_space)
+    if test $ac_cv_dnet_ifreq_has_ifr_space = yes ; then
+            AC_DEFINE(HAVE_IFREQ_IFR_SPACE, 1,
+                      [Define if ifreq struct has ifr_space.])
+    fi])
+
+dnl
 dnl Check for sockaddr_in6 struct in <netinet/in.h>
 dnl
 dnl usage:	AC_DNET_SOCKADDR_IN6
