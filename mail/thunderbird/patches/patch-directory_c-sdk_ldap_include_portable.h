$NetBSD: patch-directory_c-sdk_ldap_include_portable.h,v 1.1 2010/07/12 16:49:22 tnn Exp $

Add DragonFly support.
https://bugzilla.mozilla.org/show_bug.cgi?id=577298

--- directory/c-sdk/ldap/include/portable.h.orig	2006-10-03 20:43:40.000000000 +0000
+++ directory/c-sdk/ldap/include/portable.h
@@ -295,7 +295,7 @@ typedef char GETHOSTBYNAME_buf_t [NSLDAP
 #elif defined(HPUX10)
 #define GETHOSTBYNAME_BUF_T struct hostent_data
 #define GETHOSTBYNAME( n, r, b, l, e )	nsldapi_compat_gethostbyname_r( n, r, (char *)&b, l, e )
-#elif defined(LINUX)
+#elif defined(LINUX) || defined(DRAGONFLY)
 typedef char GETHOSTBYNAME_buf_t [NSLDAPI_NETDB_BUF_SIZE];
 #define GETHOSTBYNAME_BUF_T GETHOSTBYNAME_buf_t
 #define GETHOSTBYNAME( n, r, b, l, rp, e )  gethostbyname_r( n, r, b, l, rp, e )
@@ -317,7 +317,7 @@ typedef char GETHOSTBYNAME_buf_t [NSLDAP
 	|| defined(OSF1V4) || defined(AIX) || defined(UnixWare) \
         || defined(hpux) || defined(HPUX11) || defined(NETBSD) \
         || defined(IRIX6) || defined(FREEBSD) || defined(VMS) \
-        || defined(NTO) || defined(OPENBSD)
+        || defined(NTO) || defined(OPENBSD) || defined(DRAGONFLY)
 #define NSLDAPI_CTIME( c, b, l )        ctime_r( c, b )
 #elif defined( OSF1V3 )
 #define NSLDAPI_CTIME( c, b, l )	(ctime_r( c, b, l ) ? NULL : b)
