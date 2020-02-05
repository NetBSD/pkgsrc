$NetBSD: patch-include_ixion_model__context.hpp,v 1.1 2020/02/05 13:46:13 ryoon Exp $

* Fix build under NetBSD.

--- include/ixion/model_context.hpp.orig	2019-03-09 04:05:04.000000000 +0000
+++ include/ixion/model_context.hpp
@@ -61,7 +61,7 @@ public:
         } value;
 
         /** Initializes the cell to be empty. */
-        input_cell(nullptr_t);
+        input_cell(std::nullptr_t);
         /** Boolean cell value. */
         input_cell(bool b);
         /** The char array must be null-terminated. */
