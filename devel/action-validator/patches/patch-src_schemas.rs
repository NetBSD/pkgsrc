$NetBSD: patch-src_schemas.rs,v 1.1 2024/01/18 19:28:24 schmonz Exp $

Find installed schemastore files.

--- src/schemas.rs.orig	2024-01-18 19:15:23.979943482 +0000
+++ src/schemas.rs
@@ -5,14 +5,14 @@ use crate::validation_state::ValidationS
 pub fn validate_as_action(doc: &Value) -> ValidationState {
     validate_with_schema(
         doc,
-        include_bytes!("schemastore/src/schemas/json/github-action.json"),
+        include_bytes!("@PREFIX@/share/schemastore/schemas/json/github-action.json"),
     )
 }
 
 pub fn validate_as_workflow(doc: &Value) -> ValidationState {
     validate_with_schema(
         doc,
-        include_bytes!("schemastore/src/schemas/json/github-workflow.json"),
+        include_bytes!("@PREFIX@/share/schemastore/schemas/json/github-workflow.json"),
     )
 }
 
