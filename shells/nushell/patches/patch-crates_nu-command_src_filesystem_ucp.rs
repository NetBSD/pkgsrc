$NetBSD: patch-crates_nu-command_src_filesystem_ucp.rs,v 1.1 2024/02/10 17:28:25 pin Exp $

Allow building on NetBSD.

--- crates/nu-command/src/filesystem/ucp.rs.orig	2024-02-10 16:54:10.262829712 +0000
+++ crates/nu-command/src/filesystem/ucp.rs
@@ -281,7 +281,7 @@ const ATTR_SET: uu_cp::Preserve = uu_cp:
 fn make_attributes(preserve: Option<Value>) -> Result<uu_cp::Attributes, ShellError> {
     if let Some(preserve) = preserve {
         let mut attributes = uu_cp::Attributes {
-            #[cfg(any(target_os = "linux", target_os = "android", target_os = "macos"))]
+            #[cfg(any(target_os = "linux", target_os = "android", target_os = "macos", target_os = "netbsd"))]
             ownership: ATTR_UNSET,
             mode: ATTR_UNSET,
             timestamps: ATTR_UNSET,
@@ -296,7 +296,7 @@ fn make_attributes(preserve: Option<Valu
         // By default preseerve only mode
         Ok(uu_cp::Attributes {
             mode: ATTR_SET,
-            #[cfg(any(target_os = "linux", target_os = "android", target_os = "macos"))]
+            #[cfg(any(target_os = "linux", target_os = "android", target_os = "macos", target_os = "netbsd"))]
             ownership: ATTR_UNSET,
             timestamps: ATTR_UNSET,
             context: ATTR_UNSET,
@@ -332,7 +332,7 @@ fn parse_and_set_attribute(
         Value::String { val, .. } => {
             let attribute = match val.as_str() {
                 "mode" => &mut attribute.mode,
-                #[cfg(any(target_os = "linux", target_os = "android", target_os = "macos"))]
+                #[cfg(any(target_os = "linux", target_os = "android", target_os = "macos", target_os = "netbsd"))]
                 "ownership" => &mut attribute.ownership,
                 "timestamps" => &mut attribute.timestamps,
                 "context" => &mut attribute.context,
