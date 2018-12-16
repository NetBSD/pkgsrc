$NetBSD: patch-comm_ldap_c-sdk_include_portable.h,v 1.1 2018/12/16 08:12:15 ryoon Exp $

--- comm/ldap/c-sdk/include/portable.h.orig	2018-12-04 23:12:16.000000000 +0000
+++ comm/ldap/c-sdk/include/portable.h
@@ -122,7 +122,7 @@
  * some systems don't have the BSD re_comp and re_exec routines
  */
 #ifndef NEED_BSDREGEX
-#if ( defined( SYSV ) || defined( NETBSD ) || defined( FREEBSD ) || defined(__OpenBSD__) || defined( linux ) || defined( DARWIN )) && !defined(sgi)
+#if ( defined( SYSV ) || defined( NETBSD ) || defined(DRAGONFLY) || defined( FREEBSD ) || defined(__OpenBSD__) || defined( linux ) || defined( DARWIN )) && !defined(sgi)
 #define NEED_BSDREGEX
 #endif
 #endif
