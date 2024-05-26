$NetBSD: patch-tools_shared_versioning.py,v 1.1 2024/05/26 10:29:06 nia Exp $

Don't get version number from git, this isn't a git clone.

--- tools/shared/versioning.py.orig	2024-05-26 09:08:40.876156227 +0000
+++ tools/shared/versioning.py
@@ -1,27 +1,2 @@
-from subprocess import run
-
-from shared.common import SRC_DIR
-
-
-def get_branch_version(branch: str | None) -> str:
-    return run(
-        [
-            "git",
-            "describe",
-            *([branch] if branch else ["--dirty"]),
-            "--always",
-            "--abbrev=7",
-            "--tags",
-            "--exclude",
-            "latest",
-        ],
-        cwd=SRC_DIR,
-        text=True,
-        capture_output=True,
-        check=False,
-    ).stdout.strip()
-
-
 def generate_version() -> str:
-    version = get_branch_version(None)
-    return version or "?"
+    return "pkgsrc"
