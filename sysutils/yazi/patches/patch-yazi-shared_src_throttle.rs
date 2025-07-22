$NetBSD: patch-yazi-shared_src_throttle.rs,v 1.1 2025/07/22 14:36:15 he Exp $

Use portable_atomic.

--- yazi-shared/src/throttle.rs.orig	2025-07-22 12:15:26.994337498 +0000
+++ yazi-shared/src/throttle.rs
@@ -1,4 +1,5 @@
-use std::{fmt::Debug, mem, sync::atomic::{AtomicU64, AtomicUsize, Ordering}, time::Duration};
+use std::{fmt::Debug, mem, time::Duration};
+use portable_atomic::{AtomicU64, AtomicUsize, Ordering};
 
 use parking_lot::Mutex;
 
