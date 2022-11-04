$NetBSD: patch-src_hypothesis_extra_array__api.py,v 1.1 2022/11/04 18:34:09 adam Exp $

Fix build for Python 3.7.
https://github.com/HypothesisWorks/hypothesis/issues/3500

--- src/hypothesis/extra/array_api.py.orig	2022-11-04 18:29:04.000000000 +0000
+++ src/hypothesis/extra/array_api.py
@@ -902,7 +902,7 @@ def make_strategies_namespace(
         check_argument(
             isinstance(xp.__array_api_version__, str)
             and xp.__array_api_version__ in RELEASED_VERSIONS,
-            f"{xp.__array_api_version__=}, but xp.__array_api_version__ must "
+            f"{xp.__array_api_version__}, but xp.__array_api_version__ must "
             f"be a valid version string {RELEASED_VERSIONS}. {not_available_msg}",
         )
         api_version = xp.__array_api_version__
@@ -910,7 +910,7 @@ def make_strategies_namespace(
     else:
         check_argument(
             isinstance(api_version, str) and api_version in NOMINAL_VERSIONS,
-            f"{api_version=}, but api_version must be None, or a valid version "
+            f"{api_version}, but api_version must be None, or a valid version "
             f"string {RELEASED_VERSIONS}. {not_available_msg}",
         )
         inferred_version = False
