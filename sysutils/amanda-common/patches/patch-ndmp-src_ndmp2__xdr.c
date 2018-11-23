$NetBSD: patch-ndmp-src_ndmp2__xdr.c,v 1.2 2018/11/23 22:33:13 spz Exp $

Compat for SunOS 64-bit.

--- ndmp-src/ndmp2_xdr.c.orig	2016-02-09 22:53:39.000000000 +0000
+++ ndmp-src/ndmp2_xdr.c
@@ -3,6 +3,14 @@
  * It was generated using rpcgen.
  */
 
+#ifdef __sun
+#ifndef IXDR_PUT_U_LONG
+#define IXDR_PUT_U_LONG IXDR_PUT_U_INT32
+#endif
+#ifndef IXDR_GET_U_LONG
+#define IXDR_GET_U_LONG IXDR_GET_U_INT32
+#endif
+#endif
 #include "config.h"
 #include "ndmp2.h"
 #ifndef NDMOS_OPTION_NO_NDMP2
