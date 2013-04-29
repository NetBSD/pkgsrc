$NetBSD: patch-gui_gui.gyp,v 1.1 2013/04/29 09:52:17 ryoon Exp $

--- gui/gui.gyp.orig	2012-08-31 05:36:43.000000000 +0000
+++ gui/gui.gyp
@@ -387,7 +387,7 @@
             '../session/session_base.gyp:session_protocol',
           ],
         }],
-        ['use_libzinnia==1 and OS=="linux"', {
+        ['use_libzinnia==1 and (OS=="linux" or OS=="netbsd")', {
           'defines': [
             'USE_LIBZINNIA',
           ],
