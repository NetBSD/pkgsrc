$NetBSD: patch-third__party_waf_waflib_Tools_python.py,v 1.1 2025/12/28 10:08:32 adam Exp $

Treat Darwin as POSIX.

--- third_party/waf/waflib/Tools/python.py.orig	2025-12-28 09:17:03.532882631 +0000
+++ third_party/waf/waflib/Tools/python.py
@@ -245,7 +245,7 @@ def get_sysconfig_path(self, name):
 		# Note: we could use sysconfig.get_preferred_scheme('user') but that is Python >= 3.10 only
 		pref_scheme = 'posix_user'  # Default to *nix name
 		if Utils.unversioned_sys_platform() == 'darwin':
-			pref_scheme = 'osx_framework_user'
+			pref_scheme = 'posix_user'
 		elif Utils.unversioned_sys_platform() == 'win32':
 			pref_scheme = 'nt_user'
 		cmd = self.env.PYTHON + ["-c", "import sysconfig; print(sysconfig.get_path(%r, %r, {'userbase': %r}))" % (name, pref_scheme, self.env.PREFIX)]
