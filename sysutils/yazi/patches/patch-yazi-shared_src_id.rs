$NetBSD: patch-yazi-shared_src_id.rs,v 1.1 2025/07/22 14:36:15 he Exp $

Use portable_atomic.

--- yazi-shared/src/id.rs.orig	2025-07-22 12:15:08.593611533 +0000
+++ yazi-shared/src/id.rs
@@ -1,4 +1,5 @@
-use std::{fmt::Display, str::FromStr, sync::atomic::{AtomicU64, Ordering}};
+use std::{fmt::Display, str::FromStr};
+use portable_atomic::{AtomicU64, Ordering};
 
 use serde::{Deserialize, Serialize};
 
