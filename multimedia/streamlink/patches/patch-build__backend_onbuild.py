$NetBSD: patch-build__backend_onbuild.py,v 1.1 2026/03/02 20:31:12 yhardy Exp $

Match the call parameters with how it is used by our py-versioningit package.

--- build_backend/onbuild.py.orig	2024-11-04 16:33:10.000000000 +0000
+++ build_backend/onbuild.py
@@ -22,11 +22,12 @@ except ImportError:  # pragma: no cover
 def onbuild(
     *,
     is_source: bool,
-    template_fields: dict[str, Any],
-    params: dict[str, Any],
+    template_fields: Optional[dict[str, Any]] = {},
+    params: Optional[dict[str, Any]] = {},
     # backward compatibility for `versioningit <3.0.0`
     build_dir: str | Path | None = None,
     file_provider: SetuptoolsFileProvider | None = None,
+    version: Optional[str] = None
 ):
     """
     Remove the ``versioningit`` build-requirement from Streamlink's source distribution.
@@ -49,7 +50,8 @@ def onbuild(
         raise RuntimeError("Missing file_provider or build_dir")
 
     pkg_dir: Path = base_dir / "src" if is_source else base_dir
-    version: str = template_fields["version"]
+    if version == None:
+        version = template_fields["version"]
     cmproxy: Proxy[str]
 
     # Remove versioningit from ``build-system.requires`` in ``pyproject.toml``
