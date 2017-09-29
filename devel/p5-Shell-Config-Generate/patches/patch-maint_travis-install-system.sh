$NetBSD: patch-maint_travis-install-system.sh,v 1.1 2017/09/29 13:24:29 wiz Exp $

Fix unportable test(1) operator.

--- maint/travis-install-system.sh.orig	2017-09-01 13:39:02.000000000 +0000
+++ maint/travis-install-system.sh
@@ -4,7 +4,7 @@
 set -euo pipefail
 IFS=$'\n\t'
 
-if [ "a" == "a" ]; then
+if [ "a" = "a" ]; then
 
   cd `mktemp -d`
   wget http://fishshell.com/files/2.2.0/fish-2.2.0.tar.gz
