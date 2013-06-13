$NetBSD: patch-ospf_vertex.hh,v 1.1 2013/06/13 21:48:09 joerg Exp $

--- ospf/vertex.hh.orig	2013-06-13 19:14:46.000000000 +0000
+++ ospf/vertex.hh
@@ -60,6 +60,11 @@ class Vertex {
 	return _nodeid == other.get_nodeid() && _t ==  other.get_type();
     }
 
+    bool operator!=(const Vertex& other) const {
+	XLOG_ASSERT(get_version() == other.get_version());
+	return _nodeid != other.get_nodeid() || _t !=  other.get_type();
+    }
+
     void set_version(OspfTypes::Version v) {
 	_version = v;
     }
