$NetBSD: patch-libmemcached_byteorder.cc,v 1.1 2013/09/12 14:20:56 fhajny Exp $

Need ntohll/htonll defined.
--- libmemcached/byteorder.cc.orig	2013-04-03 04:22:00.000000000 +0000
+++ libmemcached/byteorder.cc
@@ -36,6 +36,9 @@
  */
 
 #include "mem_config.h"
+#ifdef __sun
+# include "sys/byteorder.h"
+#endif
 #include "libmemcached/byteorder.h"
 
 /* Byte swap a 64-bit number. */
