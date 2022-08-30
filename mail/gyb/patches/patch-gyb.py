$NetBSD: patch-gyb.py,v 1.1 2022/08/30 12:20:15 sborrill Exp $

Set default config path to PKG_SYSCONFDIR

--- gyb.py.orig	2022-08-25 10:03:41.833502873 +0100
+++ gyb.py	2022-08-25 10:06:19.651616395 +0100
@@ -241,7 +241,7 @@
   parser.add_argument('--config-folder',
     dest='config_folder',
     help='Optional: Alternate folder to store config and credentials',
-    default=getProgPath())
+    default='PKG_SYSCONFDIR')
   parser.add_argument('--cleanup',
           action='store_true',
           dest='cleanup',
