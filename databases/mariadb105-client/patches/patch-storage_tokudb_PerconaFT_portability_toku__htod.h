$NetBSD: patch-storage_tokudb_PerconaFT_portability_toku__htod.h,v 1.1 2021/05/23 15:32:47 nia Exp $

Detect endianness on SunOS.

--- storage/tokudb/PerconaFT/portability/toku_htod.h.orig	2020-01-26 20:43:56.000000000 +0000
+++ storage/tokudb/PerconaFT/portability/toku_htod.h
@@ -59,11 +59,23 @@ Copyright (c) 2006, 2015, Percona and/or
 
 #if defined(HAVE_ENDIAN_H)
 # include <endian.h>
+#define __BYTE_ORDER BYTE_ORDER
+#define __LITTLE_ENDIAN LITTLE_ENDIAN
+#define __BIG_ENDIAN BIG_ENDIAN
 #elif defined(HAVE_MACHINE_ENDIAN_H)
 # include <machine/endian.h>
 # define __BYTE_ORDER __DARWIN_BYTE_ORDER
 # define __LITTLE_ENDIAN __DARWIN_LITTLE_ENDIAN
 # define __BIG_ENDIAN __DARWIN_BIG_ENDIAN
+#elif defined(__sun)
+# include <sys/isa_defs.h>
+# define __BIG_ENDIAN 4321
+# define __LITTLE_ENDIAN 1234
+# if defined(_BIG_ENDIAN)
+#  define __BYTE_ORDER __BIG_ENDIAN
+# else
+#  define __BYTE_ORDER __LITTLE_ENDIAN
+# endif
 #endif
 #if !defined(__BYTE_ORDER) || \
     !defined(__LITTLE_ENDIAN) || \
