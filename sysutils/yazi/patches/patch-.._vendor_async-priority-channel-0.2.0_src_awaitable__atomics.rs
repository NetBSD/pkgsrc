$NetBSD: patch-.._vendor_async-priority-channel-0.2.0_src_awaitable__atomics.rs,v 1.1 2025/07/22 14:36:15 he Exp $

--- ../vendor/async-priority-channel-0.2.0/src/awaitable_atomics.rs.orig	2025-07-22 13:53:56.573453513 +0000
+++ ../vendor/async-priority-channel-0.2.0/src/awaitable_atomics.rs
@@ -1,8 +1,8 @@
 use event_listener::{Event, EventListener};
 use std::{
     pin::Pin,
-    sync::atomic::{AtomicU64, Ordering},
 };
+use portable_atomic::{AtomicU64, Ordering};
 
 const U64_TOP_BIT_MASK: u64 = 0x1000000000000000;
 
