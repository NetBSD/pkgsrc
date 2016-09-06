$NetBSD: patch-src_rust-installer_gen-installer.sh,v 1.1 2016/09/06 10:36:49 jperkin Exp $

Do not use /bin/echo, not guaranteed to support -n.
Unset CDPATH before printing cd output.

--- src/rust-installer/gen-installer.sh.orig	2016-07-04 18:05:18.000000000 +0000
+++ src/rust-installer/gen-installer.sh
@@ -1,4 +1,4 @@
-#!/bin/sh
+#!/bin/bash
 # Copyright 2014 The Rust Project Developers. See the COPYRIGHT
 # file at the top-level directory of this distribution and at
 # http://rust-lang.org/COPYRIGHT.
@@ -11,7 +11,7 @@
 
 set -u
 
-if [ -x /bin/echo ]; then
+if [ -x /bin/donotuseecho ]; then
     ECHO='/bin/echo'
 else
     ECHO='echo'
@@ -287,7 +287,7 @@ cp -r "$CFG_IMAGE_DIR/"* "$CFG_WORK_DIR/
 need_ok "couldn't copy source image"
 
 # Create the manifest
-manifest=`(cd "$CFG_WORK_DIR/$CFG_PACKAGE_NAME/$CFG_COMPONENT_NAME" && find . -type f | sed 's/^\.\///') | sort`
+manifest=`(unset CDPATH && cd "$CFG_WORK_DIR/$CFG_PACKAGE_NAME/$CFG_COMPONENT_NAME" >/dev/null && find . -type f | sed 's/^\.\///') | sort`
 
 # Remove files in bulk dirs
 bulk_dirs=`echo "$CFG_BULK_DIRS" | tr "," " "`
@@ -324,7 +324,7 @@ echo "$rust_installer_version" > "$versi
 
 # Copy the overlay
 if [ -n "$CFG_NON_INSTALLED_OVERLAY" ]; then
-    overlay_files=`(cd "$CFG_NON_INSTALLED_OVERLAY" && find . -type f)`
+    overlay_files=`(unset CDPATH && cd "$CFG_NON_INSTALLED_OVERLAY" >/dev/null && find . -type f)`
     for f in $overlay_files; do
 	if [ -e "$CFG_WORK_DIR/$CFG_PACKAGE_NAME/$f" ]; then err "overlay $f exists"; fi
 
