$NetBSD: patch-rapid_plugin_group__replication_libmysqlgcs_src_bindings_xcom_xcom_xcom__memory.c,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

--- rapid/plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_memory.c.orig	2021-09-14 09:08:08.000000000 +0000
+++ rapid/plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_memory.c
@@ -50,7 +50,14 @@ my_xdr_free (xdrproc_t proc, char *objp)
     is the case). This will keep this code cross-platform
     and cross-version compatible.
   */
+#ifdef __NetBSD__
+  /* NetBSD doesn't have a variadic xdrproc_t...
+   * see https://bugzilla.redhat.com/show_bug.cgi?id=1128820#c24
+   * for a similar problem */
+  (*proc) (&x, objp);
+#else
   (*proc) (&x, objp, 0);
+#endif
 }
 
 void xcom_xdr_free(xdrproc_t f, char *p)
