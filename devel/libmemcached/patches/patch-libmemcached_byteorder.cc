$NetBSD: patch-libmemcached_byteorder.cc,v 1.2 2014/04/01 13:51:56 fhajny Exp $

Need ntohll/htonll defined.
--- libmemcached/byteorder.cc.orig	2014-02-09 11:52:42.000000000 +0000
+++ libmemcached/byteorder.cc
@@ -36,6 +36,9 @@
  */
 
 #include "mem_config.h"
+#ifdef __sun
+# include "sys/byteorder.h"
+#endif
 #include "libmemcached/byteorder.h"
 
 /* Byte swap a 64-bit number. */
