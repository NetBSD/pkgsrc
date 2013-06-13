$NetBSD: patch-libproto_config__node__id.hh,v 1.1 2013/06/13 21:48:09 joerg Exp $

--- libproto/config_node_id.hh.orig	2013-06-13 19:43:57.000000000 +0000
+++ libproto/config_node_id.hh
@@ -98,6 +98,9 @@ public:
      * right-hand operand.
      */
     bool operator==(const ConfigNodeId& other) const;
+    bool operator!=(const ConfigNodeId& other) const {
+	return !(*this == other);
+    }
 
     /**
      * Return the unique node ID.
