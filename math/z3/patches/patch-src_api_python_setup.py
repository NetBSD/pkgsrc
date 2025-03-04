$NetBSD: patch-src_api_python_setup.py,v 1.3 2025/03/04 05:09:51 adam Exp $

Some platforms do not support LTO.

Do not override finalize_options(). This allows to build on all platforms.

--- src/api/python/setup.py.orig	2025-02-18 21:41:31.000000000 +0000
+++ src/api/python/setup.py
@@ -26,7 +26,7 @@ SRC_DIR_REPO = os.path.join(ROOT_DIR, '.
 SRC_DIR = SRC_DIR_LOCAL if os.path.exists(SRC_DIR_LOCAL) else SRC_DIR_REPO
 
 IS_SINGLE_THREADED = False
-ENABLE_LTO = True
+ENABLE_LTO = False
 
 IS_PYODIDE = 'PYODIDE_ROOT' in os.environ and os.environ.get('_PYTHON_HOST_PLATFORM', '').startswith('emscripten')
 
@@ -295,29 +295,6 @@ class bdist_wheel(_bdist_wheel):
         return os_version_tag
             
             
-    def finalize_options(self):
-        if BUILD_ARCH is not None and BUILD_PLATFORM is not None:
-            os_version_tag = '_'.join(BUILD_OS_VERSION) if BUILD_OS_VERSION is not None else 'xxxxxx'
-            os_version_tag = self.remove_build_machine_os_version(BUILD_PLATFORM, os_version_tag)
-            TAGS = {
-                # linux tags cannot be deployed - they must be auditwheel'd to pick the right compatibility tag based on imported libc symbol versions
-                ("linux", "x86_64"): "linux_x86_64",
-                ("linux", "aarch64"): "linux_aarch64",
-                # windows arm64 is not supported by pypi yet
-                ("win", "x64"): "win_amd64",
-                ("win", "x86"): "win32",
-                ("osx", "x64"): f"macosx_{os_version_tag}_x86_64",
-                ("osx", "arm64"): f"macosx_{os_version_tag}_arm64",
-                ("darwin", "x86_64"): f"macosx_{os_version_tag}_x86_64",
-                ("darwin", "x64"): f"macosx_{os_version_tag}_x86_64",
-                ("darwin", "arm64"): f"macosx_{os_version_tag}_arm64",
-                ("sequoia", "x64"): f"macosx_{os_version_tag}_x86_64",
-                ("sequoia", "x86_64"): f"macosx_{os_version_tag}_x86_64",
-                ("sequoia", "arm64"): f"macosx_{os_version_tag}_arm64",
-                ("emscripten", "wasm32"): f"emscripten_{os_version_tag}_wasm32",
-            }  # type: dict[tuple[str, str], str]
-            self.plat_name = TAGS[(BUILD_PLATFORM, BUILD_ARCH)]
-        return super().finalize_options()
 
 
 setup(
