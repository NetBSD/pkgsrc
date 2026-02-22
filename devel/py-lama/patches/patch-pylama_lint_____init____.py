$NetBSD: patch-pylama_lint_____init____.py,v 1.1 2026/02/22 11:51:38 wiz Exp $

https://github.com/klen/pylama/pull/254/files

--- pylama/lint/__init__.py.orig	2022-08-08 11:26:27.000000000 +0000
+++ pylama/lint/__init__.py
@@ -7,7 +7,7 @@ from typing import TYPE_CHECKING, Any, Dict, List, Opt
 from pkgutil import walk_packages
 from typing import TYPE_CHECKING, Any, Dict, List, Optional, Type
 
-from pkg_resources import iter_entry_points
+from importlib.metadata import entry_points
 
 LINTERS: Dict[str, Type[LinterV2]] = {}
 
@@ -58,7 +58,7 @@ for _, pname, _ in walk_packages([str(Path(__file__).p
         pass
 
 # Import installed linters
-for entry in iter_entry_points("pylama.linter"):
+for entry in entry_points(group="pylama.linter"):
     if entry.name not in LINTERS:
         try:
             LINTERS[entry.name] = entry.load()
