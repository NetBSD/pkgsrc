$NetBSD: patch-src_rust-installer_gen-install-script.sh,v 1.2 2017/02/23 09:35:16 jperkin Exp $

Do not use /bin/echo, not guaranteed to support -n.

--- src/rust-installer/gen-install-script.sh.orig	2016-07-04 18:05:18.000000000 +0000
+++ src/rust-installer/gen-install-script.sh
@@ -11,7 +11,7 @@
 
 set -u
 
-if [ -x /bin/echo ]; then
+if [ -x /bin/donotuseecho ]; then
     ECHO='/bin/echo'
 else
     ECHO='echo'
