$NetBSD: patch-rapid_plugin_group__replication_libmysqlgcs_src_bindings_xcom_xcom_xcom__memory.c,v 1.1 2017/03/16 15:46:22 maya Exp $

Workaround netbsd prototype of xdrproc_t being 2 arguments.

--- rapid/plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_memory.c.orig	2016-11-28 13:32:52.000000000 +0000
+++ rapid/plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_memory.c
@@ -43,7 +43,14 @@ my_xdr_free (xdrproc_t proc, char *objp)
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
