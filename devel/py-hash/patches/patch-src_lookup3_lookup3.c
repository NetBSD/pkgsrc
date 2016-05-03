$NetBSD: patch-src_lookup3_lookup3.c,v 1.1 2016/05/03 14:53:05 fhajny Exp $

SunOS doesn't have endian.h.

--- src/lookup3/lookup3.c.orig	2014-07-29 06:26:59.000000000 +0000
+++ src/lookup3/lookup3.c
@@ -47,7 +47,7 @@ typedef unsigned int uint32_t;
 # include <sys/param.h>  /* attempt to define endianness */
 # if defined(__APPLE__)
 #  include <architecture/byte_order.h>
-# else
+# elif !defined(__sun)
 #  include <endian.h>    /* attempt to define endianness */
 # endif
 #endif
