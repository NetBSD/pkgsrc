$NetBSD: patch-scripts_resetdeps.sh,v 1.1 2022/04/11 18:50:31 adam Exp $

Don't be destructive.

--- scripts/resetdeps.sh.orig	2022-04-11 16:50:23.000000000 +0000
+++ scripts/resetdeps.sh
@@ -1,10 +1,6 @@
 #!/bin/bash
 set -e
 set -x
-rm -rf node_modules
-rm -rf docs/node_modules
-rm -rf "workspaces/*/node_modules"
-git checkout node_modules
 node . i --ignore-scripts --no-audit --no-fund
 node . rebuild --ignore-scripts
 node scripts/bundle-and-gitignore-deps.js
