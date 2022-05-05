$NetBSD: patch-scripts_resetdeps.sh,v 1.2 2022/05/05 10:52:39 adam Exp $

Don't be destructive.

--- scripts/resetdeps.sh.orig	2022-04-26 22:02:20.000000000 +0000
+++ scripts/resetdeps.sh
@@ -1,11 +1,6 @@
 #!/bin/bash
 set -e
 set -x
-rm -rf node_modules
-rm -rf docs/node_modules
-rm -rf smoke-tests/node_modules
-rm -rf "workspaces/*/node_modules"
-git checkout node_modules
 node . i --ignore-scripts --no-audit --no-fund
 node . rebuild --ignore-scripts
 node scripts/bundle-and-gitignore-deps.js
