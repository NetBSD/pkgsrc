$NetBSD: patch-third__party_rust_authenticator_src_netbsd_mod.rs,v 1.1 2023/02/05 08:32:24 he Exp $

--- third_party/rust/authenticator/src/netbsd/mod.rs.orig	2020-09-02 20:55:30.875841045 +0000
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
