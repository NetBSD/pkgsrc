$NetBSD: patch-src_main.rs,v 1.1 2024/12/16 00:41:41 riastradh Exp $

Make git push fail with nonzero status when rejected upstream.
https://github.com/glandium/git-cinnabar/issues/338
https://github.com/glandium/git-cinnabar/issues/341
https://github.com/glandium/git-cinnabar/pull/342

--- src/main.rs.orig	2024-09-30 20:35:52.000000000 +0000
+++ src/main.rs
@@ -4845,25 +4845,29 @@ fn remote_helper_push(
                 let response = conn.unbundle(heads, file);
                 match response {
                     UnbundleResponse::Bundlev2(data) => {
-                        let mut bundle = BundleReader::new(data).unwrap();
-                        while let Some(part) = bundle.next_part().unwrap() {
-                            match part.part_type.as_bytes() {
-                                b"reply:changegroup" => {
-                                    // TODO: should check in-reply-to param.
-                                    let response = part.get_param("return").unwrap();
-                                    result = u32::from_str(response).ok();
-                                }
-                                b"error:abort" => {
-                                    let mut message =
-                                        part.get_param("message").unwrap().to_string();
-                                    if let Some(hint) = part.get_param("hint") {
-                                        message.push_str("\n\n");
-                                        message.push_str(hint);
+                        if let Ok(mut bundle) = BundleReader::new(data) {
+                            while let Ok(Some(part)) = bundle.next_part() {
+                                match part.part_type.as_bytes() {
+                                    b"reply:changegroup" => {
+                                        // TODO: should check in-reply-to param.
+                                        let response = part.get_param("return").unwrap();
+                                        result = u32::from_str(response).ok();
+                                    }
+                                    b"error:abort" => {
+                                        let mut message =
+                                            part.get_param("message").unwrap().to_string();
+                                        if let Some(hint) = part.get_param("hint") {
+                                            message.push_str("\n\n");
+                                            message.push_str(hint);
+                                        }
+                                        error!(target: "root", "{}", message);
+                                        pushed = ChangesetHeads::new();
                                     }
-                                    error!(target: "root", "{}", message);
+                                    _ => {}
                                 }
-                                _ => {}
                             }
+                        } else {
+                            pushed = ChangesetHeads::new();
                         }
                     }
                     UnbundleResponse::Raw(response) => {
