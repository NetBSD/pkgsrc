$NetBSD: patch-libmemcached_byteorder.cc,v 1.2.30.1 2017/10/15 11:26:40 spz Exp $

Find definition of ntohll() and htonll().

--- libmemcached/byteorder.cc.orig	2014-02-09 11:52:42.000000000 +0000
+++ libmemcached/byteorder.cc
@@ -36,6 +36,11 @@
  */
 
 #include "mem_config.h"
+#if defined(__sun)
+# include "sys/byteorder.h"
+#elif defined(__APPLE__)
+# include "sys/_endian.h"
+#endif
 #include "libmemcached/byteorder.h"
 
 /* Byte swap a 64-bit number. */
