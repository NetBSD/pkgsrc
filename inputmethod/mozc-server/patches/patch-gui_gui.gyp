$NetBSD: patch-gui_gui.gyp,v 1.3 2015/07/31 13:07:05 ryoon Exp $

--- gui/gui.gyp.orig	2015-06-07 07:16:23.000000000 +0000
+++ gui/gui.gyp
@@ -387,7 +387,7 @@
             '../protocol/protocol.gyp:commands_proto',
           ],
         }],
-        ['use_libzinnia==1 and OS=="linux"', {
+        ['use_libzinnia==1 and (OS=="linux" or OS=="netbsd")', {
           'defines': [
             'USE_LIBZINNIA',
           ],
