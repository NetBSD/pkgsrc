$NetBSD: patch-.._vendor_tui-textarea-0.2.0_src_widget.rs,v 1.1 2025/07/22 11:30:40 he Exp $

Use portable_atomic.

--- ../vendor/tui-textarea-0.2.0/src/widget.rs.orig	2025-07-22 09:29:29.756730488 +0000
+++ ../vendor/tui-textarea-0.2.0/src/widget.rs
@@ -1,7 +1,7 @@
 use crate::textarea::TextArea;
 use crate::util::num_digits;
 use std::cmp;
-use std::sync::atomic::{AtomicU64, Ordering};
+use portable_atomic::{AtomicU64, Ordering};
 use tui::buffer::Buffer;
 use tui::layout::Rect;
 use tui::text::Text;
