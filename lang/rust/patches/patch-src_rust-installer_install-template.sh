$NetBSD: patch-src_rust-installer_install-template.sh,v 1.1 2016/09/06 10:36:49 jperkin Exp $

Support SunOS.
Fix undefined variable warnings.

--- src/rust-installer/install-template.sh.orig	2016-07-04 18:05:18.000000000 +0000
+++ src/rust-installer/install-template.sh
@@ -352,6 +352,10 @@ get_host_triple() {
             _ostype=apple-darwin
             ;;
 
+	SunOS)
+            _ostype=unknown-solaris
+            ;;
+
 	MINGW*)
             _ostype=pc-windows-gnu
             ;;
@@ -381,7 +385,7 @@ get_host_triple() {
             ;;
 
 	*)
-	    err "unknown value from uname -s: $uname_value"
+	    err "unknown value from uname -s: $_uname_value"
 	    ;;
     esac
 
