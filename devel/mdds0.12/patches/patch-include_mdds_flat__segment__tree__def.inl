$NetBSD: patch-include_mdds_flat__segment__tree__def.inl,v 1.1 2016/02/12 13:34:45 wiz Exp $

https://gerrit.libreoffice.org/gitweb?p=core.git;a=commit;h=bead58cb4042ac42dee890e2f21ab7ea81136e54

--- include/mdds/flat_segment_tree_def.inl.orig	2015-06-11 23:53:55.000000000 +0000
+++ include/mdds/flat_segment_tree_def.inl
@@ -46,7 +46,7 @@ flat_segment_tree<_Key, _Value>::flat_se
     // We don't ever use the value of the right leaf node, but we need the
     // value to be always the same, to make it easier to check for
     // equality.
-    m_right_leaf->value_leaf.value = ::std::numeric_limits<value_type>::max();
+    m_right_leaf->value_leaf.value = init_val;
 }
 
 template<typename _Key, typename _Value>
