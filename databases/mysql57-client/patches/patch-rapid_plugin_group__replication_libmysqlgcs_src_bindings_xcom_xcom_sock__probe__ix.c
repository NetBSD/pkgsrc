$NetBSD: patch-rapid_plugin_group__replication_libmysqlgcs_src_bindings_xcom_xcom_sock__probe__ix.c,v 1.1 2017/03/16 15:46:22 maya Exp $

fix -fpermissive errors, ifc_buf is void*

--- rapid/plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/sock_probe_ix.c.orig	2016-11-28 13:32:52.000000000 +0000
+++ rapid/plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/sock_probe_ix.c
@@ -124,7 +124,7 @@ static int init_sock_probe(sock_probe *s
    interfaces. We are doing this, since the size of sockaddr differs on
    some platforms.
    */
-  for (i= 0, ptr= s->ifc.ifc_buf, end= s->ifc.ifc_buf + s->ifc.ifc_len;
+  for (i= 0, ptr=(char*) s->ifc.ifc_buf, end= (char*)s->ifc.ifc_buf + s->ifc.ifc_len;
        ptr<end;
        i++)
   {
