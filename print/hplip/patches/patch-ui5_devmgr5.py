$NetBSD: patch-ui5_devmgr5.py,v 1.1 2026/08/27 09:39:59 wiz Exp $

Adapt to Python 3.12 changes.

--- ui5/devmgr5.py.orig	2026-08-27 09:36:12.651743936 +0000
+++ ui5/devmgr5.py
@@ -1069,7 +1069,7 @@ class DevMgr5(Ui_MainWindow_Derived, Ui_MainWindow, QM
 
                 hplip_conf = configparser.ConfigParser()
                 fp = open("/etc/hp/hplip.conf", "r")
-                hplip_conf.readfp(fp)
+                hplip_conf.read_file(fp, "/etc/hp/hplip.conf")
                 fp.close()
 
                 try:
