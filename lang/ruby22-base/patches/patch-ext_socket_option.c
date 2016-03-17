$NetBSD: patch-ext_socket_option.c,v 1.1 2016/03/17 07:53:46 wiz Exp $

SVN 54139:

Thu Mar 17 11:36:27 2016  Nobuyoshi Nakada  <nobu@ruby-lang.org>

	* ext/socket/option.c (inspect_tcpi_msec): more accurate condition
	  for TCPI msec member inspection function.
	  [ruby-core:74388] [Bug #12185]

--- ext/socket/option.c.orig	2015-08-10 15:33:59.000000000 +0000
+++ ext/socket/option.c
@@ -928,7 +928,12 @@ inspect_tcpi_usec(VALUE ret, const char 
     rb_str_catf(ret, "%s%u.%06us", prefix, t / 1000000, t % 1000000);
 }
 
-#if defined(__linux__) || defined(__sun)
+#if !defined __FreeBSD__ && ( \
+    defined HAVE_STRUCT_TCP_INFO_TCPI_LAST_DATA_SENT || \
+    defined HAVE_STRUCT_TCP_INFO_TCPI_LAST_DATA_RECV || \
+    defined HAVE_STRUCT_TCP_INFO_TCPI_LAST_ACK_SENT  || \
+    defined HAVE_STRUCT_TCP_INFO_TCPI_LAST_ACK_RECV  || \
+    0)
 static void
 inspect_tcpi_msec(VALUE ret, const char *prefix, uint32_t t)
 {
