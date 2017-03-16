$NetBSD: patch-rapid_plugin_group__replication_libmysqlgcs_src_bindings_xcom_xcom_xcom__transport.c,v 1.1 2017/03/16 15:46:22 maya Exp $

Workaround netbsd prototype of xdrproc_t being 2 arguments.

--- rapid/plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_transport.c.orig	2016-11-28 13:32:52.000000000 +0000
+++ rapid/plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_transport.c
@@ -352,7 +352,11 @@ int apply_xdr(xcom_proto x_proto, gpoint
 	*/
 	if (xdr.x_ops){
 		xdr.x_public = (caddr_t)&x_proto; /* Supply protocol version in user field of xdr */
+#ifdef __NetBSD__
+		s = xdrfunc(&xdr, xdrdata);
+#else
 		s = xdrfunc(&xdr, xdrdata, 0);
+#endif
 	}
 	xdr_destroy(&xdr);
 	return s;
@@ -589,7 +593,11 @@ xdr_proto_sizeof (xcom_proto x_proto, xd
     is the case). This will keep this code cross-platform
     and cross-version compatible.
   */
+#ifdef __NetBSD__
+  stat = func (&x, data);
+#else
   stat = func (&x, data, 0);
+#endif
   free (x.x_private);
   // x_handy is int type for old XDR
   return stat == TRUE ? (uint64_t)x.x_handy : 0;
