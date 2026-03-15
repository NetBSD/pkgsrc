$NetBSD: patch-include_pybind11_detail_holder__caster__foreign__helpers.h,v 1.1 2026/03/15 16:55:56 tnn Exp $

Try to work around https://github.com/pybind/pybind11/issues/5989
which broke ham/gnuradio-digital and maybe others.

--- include/pybind11/detail/holder_caster_foreign_helpers.h.orig	2026-03-15 11:32:29.275064052 +0000
+++ include/pybind11/detail/holder_caster_foreign_helpers.h
@@ -37,7 +37,11 @@ struct holder_caster_foreign_helpers {
         // object derives from enable_shared_from_this;
         // try to reuse an existing shared_ptr if one is known
         if (auto existing = try_get_shared_from_this(value)) {
-            *holder_out = std::static_pointer_cast<type>(existing);
+            auto tmp = std::dynamic_pointer_cast<type>(existing);
+            if (!tmp) {
+                return false;
+            }
+            *holder_out = std::move(tmp);
             return true;
         }
         return false;
