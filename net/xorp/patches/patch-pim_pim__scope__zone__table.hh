$NetBSD: patch-pim_pim__scope__zone__table.hh,v 1.1 2013/06/13 21:48:09 joerg Exp $

--- pim/pim_scope_zone_table.hh.orig	2013-06-13 19:32:12.000000000 +0000
+++ pim/pim_scope_zone_table.hh
@@ -54,6 +54,9 @@ public:
     const IPvXNet& scope_zone_prefix() const { return (_scope_zone_prefix); }
     bool is_scope_zone() const { return (_is_scope_zone); }
     bool operator==(const PimScopeZoneId& other) const;
+    bool operator!=(const PimScopeZoneId& other) const {
+	return !(*this == other);
+    }
     bool is_overlap(const PimScopeZoneId& other) const;
     bool contains(const IPvXNet& ipvxnet) const;
     bool contains(const IPvX& ipvx) const;
