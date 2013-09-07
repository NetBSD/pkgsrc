$NetBSD: patch-gui_gui.gyp,v 1.2 2013/09/07 18:42:14 ryoon Exp $

--- gui/gui.gyp.orig	2013-08-28 05:26:12.000000000 +0000
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
