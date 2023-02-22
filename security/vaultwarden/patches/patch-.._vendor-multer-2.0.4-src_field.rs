$NetBSD: patch-.._vendor-multer-2.0.4-src_field.rs,v 1.1 2023/02/22 16:28:37 hauke Exp $

Upstream tries to pull a patched version from a git repo during build

<https://github.com/BlackDex/multer-rs/commit/477d16b7fa0f361b5c2a5ba18a5b28bec6d26a8a>,

which does not work in a pkgsrc build. Instead, we apply the patch here.

--- ../vendor/multer-2.0.4/src/field.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/multer-2.0.4/src/field.rs
@@ -68,7 +68,17 @@ impl<'r> Field<'r> {
         idx: usize,
         content_disposition: ContentDisposition,
     ) -> Self {
-        let content_type = helpers::parse_content_type(&headers);
+        let mut content_type = helpers::parse_content_type(&headers);
+
+        // This is a special check/patch to help Vaultwarden parse the attachments sent by the Mobile clients to be valid.
+        // Because the Mobile Bitwarden clients do not include the Content-Type it gets parsed as a string instead of a bytes.
+        // Issue @ Vaultwarden: https://github.com/dani-garcia/vaultwarden/issues/2644
+        // Issue @ Bitwarden: https://github.com/bitwarden/mobile/issues/2018
+        // Issue @ Rocket: https://github.com/SergioBenitez/Rocket/issues/2299
+        if content_type.is_none() && content_disposition.file_name.is_some() && content_disposition.field_name == Some("data".to_string()) {
+            content_type = Some(mime::APPLICATION_OCTET_STREAM);
+        }
+
         Field {
             state,
             headers,
