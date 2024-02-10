$NetBSD: patch-config.bzl,v 1.2 2024/02/10 01:17:27 ryoon Exp $

--- config.bzl.orig	2023-12-14 11:23:07.849816899 +0000
+++ config.bzl
@@ -35,16 +35,16 @@
 
 BRANDING = "Mozc"
 
-LINUX_MOZC_BROWSER_COMMAND = "/usr/bin/xdg-open"
-LINUX_MOZC_ICONS_DIR = "/usr/share/icons/mozc"
-LINUX_MOZC_SERVER_DIR = "/usr/lib/mozc"
+LINUX_MOZC_BROWSER_COMMAND = "@PREFIX@/bin/xdg-open"
+LINUX_MOZC_ICONS_DIR = "@PREFIX@/share/icons/mozc"
+LINUX_MOZC_SERVER_DIR = "@PREFIX@/libexec"
 LINUX_MOZC_DOCUMENT_DIR = LINUX_MOZC_SERVER_DIR + "/documents"
-IBUS_COMPONENT_DIR = "/usr/share/ibus/component"
-IBUS_MOZC_INSTALL_DIR = "/usr/share/ibus-mozc"
+IBUS_COMPONENT_DIR = "@PREFIX@/share/ibus/component"
+IBUS_MOZC_INSTALL_DIR = "@PREFIX@/share/ibus-mozc"
 IBUS_MOZC_ICON_PATH = IBUS_MOZC_INSTALL_DIR + "/product_icon.png"
-IBUS_MOZC_PATH = "/usr/lib/ibus-mozc/ibus-engine-mozc"
-EMACS_MOZC_CLIENT_DIR = "/usr/share/emacs/site-lisp/emacs-mozc"
-EMACS_MOZC_HELPER_DIR = "/usr/bin"
+IBUS_MOZC_PATH = "@PREFIX@/libexec/ibus-engine-mozc"
+EMACS_MOZC_CLIENT_DIR = "@PREFIX@/share/emacs/site-lisp/emacs-mozc"
+EMACS_MOZC_HELPER_DIR = "@PREFIX@/bin"
 
 MACOS_BUNDLE_ID_PREFIX = "org.mozc.inputmethod.Japanese"
 MACOS_MIN_OS_VER = "11.0"
