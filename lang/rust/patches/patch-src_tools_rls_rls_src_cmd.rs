$NetBSD: patch-src_tools_rls_rls_src_cmd.rs,v 1.6 2022/01/21 23:20:36 he Exp $

Use 32-bit atomic instead of 64-bit; latter may not be available on
32-bit platforms (powerpc, earmv7).

--- src/tools/rls/rls/src/cmd.rs.orig	2019-04-10 18:46:16.000000000 +0000
+++ src/tools/rls/rls/src/cmd.rs
@@ -7,7 +7,7 @@ use crate::config::Config;
 use crate::server::{self, LsService, Notification, Request, RequestId};
 use rls_analysis::{AnalysisHost, Target};
 use rls_vfs::Vfs;
-use std::sync::atomic::{AtomicU64, Ordering};
+use std::sync::atomic::{AtomicU32, Ordering};
 
 use lsp_types::{
     ClientCapabilities, CodeActionContext, CodeActionParams, CompletionItem,
@@ -316,8 +316,8 @@ fn url(file_name: &str) -> Url {
 }
 
 fn next_id() -> RequestId {
-    static ID: AtomicU64 = AtomicU64::new(1);
-    RequestId::Num(ID.fetch_add(1, Ordering::SeqCst))
+    static ID: AtomicU32 = AtomicU32::new(1);
+    RequestId::Num(ID.fetch_add(1, Ordering::SeqCst) as u64)
 }
 
 // Custom reader and output for the RLS server.
