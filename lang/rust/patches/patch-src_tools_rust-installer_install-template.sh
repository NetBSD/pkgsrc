$NetBSD: patch-src_tools_rust-installer_install-template.sh,v 1.1 2017/11/16 19:48:24 jperkin Exp $

Support SunOS.

--- src/tools/rust-installer/install-template.sh.orig	2017-10-09 20:07:27.000000000 +0000
+++ src/tools/rust-installer/install-template.sh
@@ -348,6 +348,10 @@ get_host_triple() {
             _ostype=unknown-openbsd
             ;;
 
+	SunOS)
+            _ostype=sun-solaris
+            ;;
+
 	Darwin)
             _ostype=apple-darwin
             ;;
