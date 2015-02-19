$NetBSD: patch-src_lib_core_sink-machine.c,v 1.1 2015/02/19 22:23:16 joerg Exp $

--- src/lib/core/sink-machine.c.orig	2015-02-19 20:43:52.000000000 +0000
+++ src/lib/core/sink-machine.c
@@ -123,6 +123,12 @@ static xmlNodePtr bt_sink_machine_persis
   return(node);
 }
 
+static void bt_sink_machine_persistence_load_helper(BtPersistenceInterface *parent_iface, BtPersistence *result, xmlNodePtr node, const BtPersistenceLocation * const location, ...) {
+  va_list ap;
+  va_start(ap, location);
+  parent_iface->load(BT_TYPE_MACHINE,result,node,location,NULL, ap);
+}
+
 static BtPersistence *bt_sink_machine_persistence_load(const GType type, const BtPersistence * const persistence, xmlNodePtr node, const BtPersistenceLocation * const location, GError **err, va_list var_args) {
   BtSinkMachine *self;
   BtPersistence *result;
@@ -164,7 +170,7 @@ static BtPersistence *bt_sink_machine_pe
   
   // load parent class stuff
   parent_iface=g_type_interface_peek_parent(BT_PERSISTENCE_GET_INTERFACE(result));
-  parent_iface->load(BT_TYPE_MACHINE,result,node,location,NULL,NULL);
+  bt_sink_machine_persistence_load_helper(parent_iface, result, node, location);
 
   return(result);
 }
