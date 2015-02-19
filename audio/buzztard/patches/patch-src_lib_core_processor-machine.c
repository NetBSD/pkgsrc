$NetBSD: patch-src_lib_core_processor-machine.c,v 1.1 2015/02/19 22:23:16 joerg Exp $

--- src/lib/core/processor-machine.c.orig	2009-03-23 18:43:53.000000000 +0000
+++ src/lib/core/processor-machine.c
@@ -97,6 +97,12 @@ static xmlNodePtr bt_processor_machine_p
   return(node);
 }
 
+static void bt_processor_machine_persistence_load_helper(BtPersistenceInterface *parent_iface, BtPersistence *result, xmlNodePtr node, const BtPersistenceLocation * const location, ...) {
+  va_list ap;
+  va_start(ap, location);
+  parent_iface->load(BT_TYPE_MACHINE,result,node,location,NULL, ap);
+}
+
 static BtPersistence *bt_processor_machine_persistence_load(const GType type, const BtPersistence * const persistence, xmlNodePtr node, const BtPersistenceLocation * const location, GError **err, va_list var_args) {
   BtProcessorMachine *self;
   BtPersistence *result;
@@ -147,7 +153,7 @@ static BtPersistence *bt_processor_machi
   
   // load parent class stuff
   parent_iface=g_type_interface_peek_parent(BT_PERSISTENCE_GET_INTERFACE(result));
-  parent_iface->load(BT_TYPE_MACHINE,result,node,location,NULL,NULL);
+  bt_processor_machine_persistence_load_helper(parent_iface, result, node, location);
 
   return(result);
 }
