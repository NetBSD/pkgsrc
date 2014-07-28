$NetBSD: patch-ndmp-src_ndmp4__xdr.c,v 1.1 2014/07/28 15:53:44 jperkin Exp $

Compat for SunOS 64-bit.

--- ndmp-src/ndmp4_xdr.c.orig	2012-02-21 11:38:58.000000000 +0000
+++ ndmp-src/ndmp4_xdr.c
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
 #include "ndmp4.h"
 #ifndef NDMOS_OPTION_NO_NDMP4
 #define ndmp4_u_quad unsigned long long
