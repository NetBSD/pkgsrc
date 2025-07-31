$NetBSD: patch-.._vendor_tui-textarea-0.2.4_src_widget.rs,v 1.1 2025/07/31 08:06:28 pin Exp $

Use portable_atomic.

--- ../vendor/tui-textarea-0.2.4/src/widget.rs.orig	2025-07-31 07:27:01.722450164 +0000
+++ ../vendor/tui-textarea-0.2.4/src/widget.rs
@@ -5,7 +5,7 @@ use crate::tui::text::Text;
 use crate::tui::widgets::{Paragraph, Widget};
 use crate::util::num_digits;
 use std::cmp;
-use std::sync::atomic::{AtomicU64, Ordering};
+use portable_atomic::{AtomicU64, Ordering};
 
 // &mut 'a (u16, u16, u16, u16) is not available since Renderer instance totally takes over the ownership of TextArea
 // instance. In the case, the TextArea instance cannot be accessed from any other objects since it is mutablly
