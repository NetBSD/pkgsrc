$NetBSD: patch-scripts_submodules_versions.mk,v 1.1 2021/03/03 12:05:41 nia Exp $

--- scripts/submodules/versions.mk.orig	2020-04-30 07:46:10.000000000 +0000
+++ scripts/submodules/versions.mk
@@ -111,7 +111,7 @@ __bump-version-%:
 
 __bump-branch-%:
 	@if [ "$(BRANCH)" = "" ]; then echo "Usage: make bump-branch-$* BRANCH=<branch> REMOTE_BRANCH=<remote branch>"; exit 1; fi
-	@if [ "$(REMOTE_BRANCH)" == "" ]; then echo "Usage: make bump-branch-$* BRANCH=<branch> REMOTE_BRANCH=<remote branch>"; exit 1; fi
+	@if [ "$(REMOTE_BRANCH)" = "" ]; then echo "Usage: make bump-branch-$* BRANCH=<branch> REMOTE_BRANCH=<remote branch>"; exit 1; fi
 	$(PYTHON) $(SCRIPT) $(SUBMODULES_CONFIG_FILE) set-branch $* $(BRANCH)
 	$(PYTHON) $(SCRIPT) $(SUBMODULES_CONFIG_FILE) set-remote-branch $* $(REMOTE_BRANCH)
 	@if [ "$(COMMIT)" = "1" ]; then echo "[submodules] Bump $* to switch to $(BRANCH) $(REMOTE BRANCH)." | git commit -F - $(SUBMODULES_CONFIG_FILE); fi
