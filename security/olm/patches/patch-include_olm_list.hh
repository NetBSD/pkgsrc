$NetBSD: patch-include_olm_list.hh,v 1.1 2025/04/18 11:22:59 adam Exp $

Fix for error: cannot assign to variable 'other_pos' with const-qualified type 'T *const'

--- include/olm/list.hh.orig	2025-04-18 11:20:41.096897667 +0000
+++ include/olm/list.hh
@@ -99,7 +99,7 @@ public:
             return *this;
         }
         T * this_pos = _data;
-        T * const other_pos = other._data;
+        T * other_pos = other._data;
         while (other_pos != other._end) {
             *this_pos = *other;
             ++this_pos;
