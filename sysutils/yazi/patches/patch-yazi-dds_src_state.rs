$NetBSD: patch-yazi-dds_src_state.rs,v 1.1 2025/07/22 14:36:15 he Exp $

Use portable_atomic.

--- yazi-dds/src/state.rs.orig	2025-07-22 13:30:48.088532978 +0000
+++ yazi-dds/src/state.rs
@@ -1,4 +1,5 @@
-use std::{collections::HashMap, mem, ops::Deref, sync::atomic::{AtomicU64, Ordering}, time::UNIX_EPOCH};
+use std::{collections::HashMap, mem, ops::Deref, time::UNIX_EPOCH};
+use portable_atomic::{AtomicU64, Ordering};
 
 use anyhow::Result;
 use parking_lot::RwLock;
