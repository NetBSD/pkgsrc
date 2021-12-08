$NetBSD: patch-test_dependency__source_test__pip.py,v 1.1 2021/12/08 14:35:00 wiz Exp $

https://github.com/trailofbits/pip-audit/commit/8d3e8137fc25a84c077f17909b033bd6752671f1

--- test/dependency_source/test_pip.py.orig	2021-12-06 19:13:47.000000000 +0000
+++ test/dependency_source/test_pip.py
@@ -7,7 +7,6 @@ import pretend  # type: ignore
 import pytest
 from packaging.version import Version
 
-import pip_audit
 from pip_audit._dependency_source import pip
 from pip_audit._service.interface import ResolvedDependency, SkippedDependency
 
@@ -16,14 +15,11 @@ def test_pip_source():
     source = pip.PipSource()
 
     # We're running under pytest, so we can safely assume that pytest is in
-    # our execution environment. We're also running pip_audit itself, so we
-    # can safely test for ourselves.
+    # our execution environment.
     pytest_spec = ResolvedDependency(name="pytest", version=Version(pytest.__version__))
-    pip_audit_spec = ResolvedDependency(name="pip-audit", version=Version(pip_audit.__version__))
 
     specs = list(source.collect())
     assert pytest_spec in specs
-    assert pip_audit_spec in specs
 
 
 def test_pip_source_warns_about_old_pip(monkeypatch):
