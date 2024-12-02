$NetBSD: patch-gyb.py,v 1.3 2024/12/02 08:44:46 sborrill Exp $

Set default config path to PKG_SYSCONFDIR
Disable automatic update check

--- gyb.py.orig	2024-08-09 12:47:00.000000000 +0100
+++ gyb.py	2024-12-02 08:32:56.843937255 +0000
@@ -244,7 +244,7 @@
   parser.add_argument('--config-folder',
     dest='config_folder',
     help='Optional: Alternate folder to store config and credentials',
-    default=getProgPath())
+    default='PKG_SYSCONFDIR')
   parser.add_argument('--cleanup',
           action='store_true',
           dest='cleanup',
@@ -2069,7 +2069,7 @@
   if options.debug:
     httplib2.debuglevel = 4
 
-  doGYBCheckForUpdates(debug=options.debug)
+#  doGYBCheckForUpdates(debug=options.debug)
   if options.version:
     print(getGYBVersion())
     print('Path: %s' % getProgPath())
