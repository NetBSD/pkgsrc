$NetBSD: patch-setup_build__environment.py,v 1.5 2018/02/01 16:05:56 wiz Exp $

Always build like on Linux.

--- setup/build_environment.py.orig	2017-08-25 03:47:17.000000000 +0000
+++ setup/build_environment.py
@@ -93,8 +93,8 @@ def get_sip_dir():
 pyqt['pyqt_sip_dir'] = get_sip_dir()
 pyqt['sip_inc_dir'] = os.environ.get('SIP_INC_DIR', sysconfig.get_path('include'))
 
-glib_flags = subprocess.check_output([PKGCONFIG, '--libs', 'glib-2.0']).strip() if islinux or ishaiku else ''
-fontconfig_flags = subprocess.check_output([PKGCONFIG, '--libs', 'fontconfig']).strip() if islinux or ishaiku else ''
+glib_flags = subprocess.check_output([PKGCONFIG, '--libs', 'glib-2.0']).strip()
+fontconfig_flags = subprocess.check_output([PKGCONFIG, '--libs', 'fontconfig']).strip()
 qt_inc = pyqt['inc']
 qt_lib = pyqt['lib']
 ft_lib_dirs = []
