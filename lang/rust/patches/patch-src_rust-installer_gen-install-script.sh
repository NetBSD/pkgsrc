$NetBSD: patch-src_rust-installer_gen-install-script.sh,v 1.1 2016/09/06 10:36:49 jperkin Exp $

Do not use /bin/echo, not guaranteed to support -n.

--- src/rust-installer/gen-install-script.sh.orig	2016-07-04 18:05:18.000000000 +0000
+++ src/rust-installer/gen-install-script.sh
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
