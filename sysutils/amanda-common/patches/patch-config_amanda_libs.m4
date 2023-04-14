$NetBSD: patch-config_amanda_libs.m4,v 1.1 2023/04/14 22:58:24 nia Exp $

Shell portability.

--- config/amanda/libs.m4.orig	2016-02-09 22:52:50.000000000 +0000
+++ config/amanda/libs.m4
@@ -391,22 +391,22 @@ x=CURLOPT_VERBOSE;
       LIBCURL_USE_OPENSSL=yes
      _libcurl_configures=`$_libcurl_config --configure`
      for _libcurl_configure in $_libcurl_configures ; do
-	if [[[ $_libcurl_configure = \'--with-nss* ]]]; then
+	if [[ $_libcurl_configure = \'--with-nss* ]]; then
 	    LIBCURL_USE_NSS=yes
 	fi
-	if [[[ $_libcurl_configure = \'--without-nss* ]]]; then
+	if [[ $_libcurl_configure = \'--without-nss* ]]; then
 	    LIBCURL_USE_NSS=no
 	fi
-	if [[[ $_libcurl_configure = \'--with-gnutls* ]]]; then
+	if [[ $_libcurl_configure = \'--with-gnutls* ]]; then
 	    LIBCURL_USE_GNUTLS=yes
 	fi
-	if [[[ $_libcurl_configure = \'--without-gnutls* ]]]; then
+	if [[ $_libcurl_configure = \'--without-gnutls* ]]; then
 	    LIBCURL_USE_GNUTLS=no
 	fi
-	if [[[ $_libcurl_configure = \'--with-ssl* ]]]; then
+	if [[ $_libcurl_configure = \'--with-ssl* ]]; then
 	    LIBCURL_USE_OPENSSL=yes
 	fi
-	if [[[ $_libcurl_configure = \'--without-ssl* ]]]; then
+	if [[ $_libcurl_configure = \'--without-ssl* ]]; then
 	    LIBCURL_USE_OPENSSL=no
 	fi
      done
