$NetBSD: patch-src_tools_rls_rls_src_server_io.rs,v 1.7 2022/01/21 23:20:36 he Exp $

Use 32-bit atomic instead of 64-bit; latter may not be available on
32-bit platforms (powerpc, earmv7).

--- src/tools/rls/rls/src/server/io.rs.orig	2019-05-20 12:10:32.000000000 +0000
+++ src/tools/rls/rls/src/server/io.rs
@@ -5,7 +5,7 @@ use crate::lsp_data::{LSPNotification, L
 
 use std::fmt;
 use std::io::{self, BufRead, Write};
-use std::sync::atomic::{AtomicU64, Ordering};
+use std::sync::atomic::{AtomicU32, Ordering};
 use std::sync::Arc;
 
 use jsonrpc_core::{self as jsonrpc, response, version, Id};
@@ -169,13 +169,13 @@ pub trait Output: Sync + Send + Clone + 
 /// An output that sends notifications and responses on `stdout`.
 #[derive(Clone)]
 pub(super) struct StdioOutput {
-    next_id: Arc<AtomicU64>,
+    next_id: Arc<AtomicU32>,
 }
 
 impl StdioOutput {
     /// Constructs a new `stdout` output.
     pub(crate) fn new() -> StdioOutput {
-        StdioOutput { next_id: Arc::new(AtomicU64::new(1)) }
+        StdioOutput { next_id: Arc::new(AtomicU32::new(1)) }
     }
 }
 
@@ -192,7 +192,7 @@ impl Output for StdioOutput {
     }
 
     fn provide_id(&self) -> RequestId {
-        RequestId::Num(self.next_id.fetch_add(1, Ordering::SeqCst))
+        RequestId::Num(self.next_id.fetch_add(1, Ordering::SeqCst) as u64)
     }
 }
 
