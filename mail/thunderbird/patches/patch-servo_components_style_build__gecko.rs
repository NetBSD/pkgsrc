$NetBSD: patch-servo_components_style_build__gecko.rs,v 1.1 2018/12/16 08:12:16 ryoon Exp $

--- servo/components/style/build_gecko.rs.orig	2018-12-04 23:11:55.000000000 +0000
+++ servo/components/style/build_gecko.rs
@@ -556,6 +556,8 @@ mod bindings {
                 .borrowed_type(ty)
                 .zero_size_type(ty, &structs_types);
         }
+        builder = builder
+            .raw_line(format!("pub use gecko_bindings::structs::root::*;"));
         write_binding_file(builder, BINDINGS_FILE, &fixups);
     }
 
