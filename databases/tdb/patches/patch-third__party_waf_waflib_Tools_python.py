$NetBSD: patch-third__party_waf_waflib_Tools_python.py,v 1.1 2025/08/12 09:10:58 adam Exp $

Always use POSIX scheme to be consistent across platforms.

--- third_party/waf/waflib/Tools/python.py.orig	2025-08-12 09:06:59.808276471 +0000
+++ third_party/waf/waflib/Tools/python.py
@@ -244,10 +244,6 @@ def get_sysconfig_path(self, name):
 		# If project wide PREFIX is set, construct the install directory based on this
 		# Note: we could use sysconfig.get_preferred_scheme('user') but that is Python >= 3.10 only
 		pref_scheme = 'posix_user'  # Default to *nix name
-		if Utils.unversioned_sys_platform() == 'darwin':
-			pref_scheme = 'osx_framework_user'
-		elif Utils.unversioned_sys_platform() == 'win32':
-			pref_scheme = 'nt_user'
 		cmd = self.env.PYTHON + ["-c", "import sysconfig; print(sysconfig.get_path(%r, %r, {'userbase': %r}))" % (name, pref_scheme, self.env.PREFIX)]
 	else:
 		cmd = self.env.PYTHON + ["-c", "import sysconfig; print(sysconfig.get_path(%r))" % name]
