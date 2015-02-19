$NetBSD: patch-src_lib_core_source-machine.c,v 1.1 2015/02/19 22:23:16 joerg Exp $

--- src/lib/core/source-machine.c.orig	2015-02-19 20:47:08.000000000 +0000
+++ src/lib/core/source-machine.c
@@ -91,6 +91,12 @@ static xmlNodePtr bt_source_machine_pers
   return(node);
 }
 
+static void bt_source_machine_persistence_load_helper(BtPersistenceInterface *parent_iface, BtPersistence *result, xmlNodePtr node, const BtPersistenceLocation * const location, ...) {
+  va_list ap;
+  va_start(ap, location);
+  parent_iface->load(BT_TYPE_MACHINE,result,node,location,NULL, ap);
+}
+
 static BtPersistence *bt_source_machine_persistence_load(const GType type, const BtPersistence * const persistence, xmlNodePtr node, const BtPersistenceLocation * const location, GError **err, va_list var_args) {
   BtSourceMachine *self;
   BtPersistence *result;
@@ -133,7 +139,7 @@ static BtPersistence *bt_source_machine_
   
   // load parent class stuff
   parent_iface=g_type_interface_peek_parent(BT_PERSISTENCE_GET_INTERFACE(result));
-  parent_iface->load(BT_TYPE_MACHINE,result,node,location,NULL,NULL);
+  bt_source_machine_persistence_load_helper(parent_iface, result, node, location);
 
   return(result);
 }
