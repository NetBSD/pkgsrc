$NetBSD: patch-config.bzl,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* For pkgsrc layout.

--- config.bzl.orig	2021-02-15 05:04:34.000000000 +0000
+++ config.bzl
@@ -30,9 +30,9 @@
 
 BRANDING = "Mozc"
 
-LINUX_MOZC_SERVER_DIRECTORY = "/usr/lib/mozc"
-IBUS_MOZC_ICON_PATH = "/usr/share/ibus-mozc/product_icon.png"
-IBUS_MOZC_PATH = "/usr/lib/ibus-mozc/ibus-engine-mozc"
+LINUX_MOZC_SERVER_DIRECTORY = "@PREFIX@/libexec"
+IBUS_MOZC_ICON_PATH = "@PREFIX@/share/ibus-mozc/product_icon.png"
+IBUS_MOZC_PATH = "@PREFIX@/libexec/ibus-engine-mozc"
 
 MACOS_BUNDLE_ID_PREFIX = "org.mozc.inputmethod.Japanese"
 MACOS_MIN_OS_VER = "10.12"
