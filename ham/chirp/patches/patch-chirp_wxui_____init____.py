$NetBSD: patch-chirp_wxui_____init____.py,v 1.1 2026/09/28 22:21:18 gdt Exp $

Patch out phone-home version check as a bug.

Not reported upstream because this is a difference of opinion about
respecting user privacy.

--- chirp/wxui/__init__.py.orig	2026-08-07 09:10:34.000000000 +0000
+++ chirp/wxui/__init__.py
@@ -241,8 +241,8 @@ def chirpmain():
     if args.action:
         wx.CallAfter(getattr(mainwindow, '_menu_%s' % args.action), None)
 
-    report.check_for_updates(
-        lambda ver: wx.CallAfter(main.display_update_notice, ver))
+    #report.check_for_updates(
+    #    lambda ver: wx.CallAfter(main.display_update_notice, ver))
 
     if sys.platform == 'linux':
         try:
