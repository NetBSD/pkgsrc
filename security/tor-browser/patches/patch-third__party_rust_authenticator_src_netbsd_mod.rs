$NetBSD: patch-third__party_rust_authenticator_src_netbsd_mod.rs,v 1.1.2.2 2020/10/23 17:27:13 bsiegert Exp $

Add NetBSD support for U2F.

Submitted upstream:

https://github.com/mozilla/authenticator-rs/pull/116

--- third_party/rust/authenticator/src/netbsd/mod.rs.orig	2020-07-15 16:29:34.210141360 +0000
+++ third_party/rust/authenticator/src/netbsd/mod.rs
@@ -0,0 +1,10 @@
+/* This Source Code Form is subject to the terms of the Mozilla Public
+ * License, v. 2.0. If a copy of the MPL was not distributed with this
+ * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
+
+pub mod device;
+pub mod transaction;
+
+mod fd;
+mod monitor;
+mod uhid;
