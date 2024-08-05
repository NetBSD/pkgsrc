$NetBSD: patch-plugin_group__replication_libmysqlgcs_src_bindings_xcom_xcom_xcom__vp__platform.h,v 1.1 2024/08/05 01:24:00 jnemeth Exp $

--- plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_vp_platform.h.orig	2022-03-23 13:49:36.000000000 +0000
+++ plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_vp_platform.h
@@ -36,10 +36,10 @@
 #endif
 #endif
 
-#ifdef __APPLE__
-#if __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
+#if __APPLE__ || __NetBSD__
 
-/* xdr_uint64_t and xdr_uint32_t are not defined on OSX */
+/* xdr_uint64_t and xdr_uint32_t are not defined on OSX or NetBSD */
 #define xdr_uint64_t xdr_u_int64_t
 #define xdr_uint32_t xdr_u_int32_t
 #endif
