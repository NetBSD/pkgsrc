$NetBSD: patch-src_tools_rls_src_cmd.rs,v 1.1 2018/12/21 23:12:34 he Exp $

--- src/tools/rls/src/cmd.rs.orig	2018-12-18 23:12:41.000000000 +0000
+++ src/tools/rls/src/cmd.rs
@@ -17,7 +17,7 @@ use crate::config::Config;
 use crate::server::{self, LsService, Notification, Request, RequestId};
 use rls_analysis::{AnalysisHost, Target};
 use rls_vfs::Vfs;
-use std::sync::atomic::{AtomicU64, Ordering};
+use std::sync::atomic::{AtomicU32, Ordering};
 
 use languageserver_types::{
     ClientCapabilities, CodeActionContext, CodeActionParams, CompletionItem,
@@ -424,8 +424,8 @@ fn url(file_name: &str) -> Url {
 }
 
 fn next_id() -> RequestId {
-    static ID: AtomicU64 = AtomicU64::new(1);
-    RequestId::Num(ID.fetch_add(1, Ordering::SeqCst))
+    static ID: AtomicU32 = AtomicU32::new(1);
+    RequestId::Num(ID.fetch_add(1, Ordering::SeqCst) as u64)
 }
 
 // Custom reader and output for the RLS server.
