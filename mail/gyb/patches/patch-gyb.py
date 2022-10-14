$NetBSD: patch-gyb.py,v 1.2 2022/10/14 12:26:56 sborrill Exp $

Set default config path to PKG_SYSCONFDIR
Disable automatic update check

--- gyb.py.orig	2022-09-26 19:18:58.000000000 +0100
+++ gyb.py	2022-10-14 13:19:17.325498099 +0100
@@ -242,7 +242,7 @@
   parser.add_argument('--config-folder',
     dest='config_folder',
     help='Optional: Alternate folder to store config and credentials',
-    default=getProgPath())
+    default='PKG_SYSCONFDIR')
   parser.add_argument('--cleanup',
           action='store_true',
           dest='cleanup',
@@ -1964,7 +1964,7 @@
   options = SetupOptionParser(argv)
   if options.debug:
     httplib2.debuglevel = 4
-  doGYBCheckForUpdates(debug=options.debug)
+#  doGYBCheckForUpdates(debug=options.debug)
   if options.version:
     print(getGYBVersion())
     print('Path: %s' % getProgPath())
