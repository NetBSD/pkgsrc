$NetBSD: patch-setup.py,v 1.1 2015/12/11 21:40:50 riz Exp $

Rearrange installation dirs for pkgsrc, and don't install redhat files

--- setup.py.orig	2015-11-27 10:37:07.000000000 -0800
+++ setup.py	2015-12-04 12:53:42.000000000 -0800
@@ -13,19 +13,12 @@
   setup_kwargs = dict()
 
 
-storage_dirs = [ ('storage/whisper',[]), ('storage/lists',[]),
-                 ('storage/log',[]), ('storage/rrd',[]) ]
-conf_files = [ ('conf', glob('conf/*.example')) ]
+storage_dirs = [ ('@GRAPHITE_DIR@/whisper',[]), ('@GRAPHITE_DIR@/lists',[]),
+                 ('@GRAPHITE_DIR@/log',[]), ('@GRAPHITE_DIR@/rrd',[]) ]
+conf_files = [ ('@PREFIX@/@GRAPHITE_EGDIR@', glob('conf/*.example')) ]
 
 install_files = storage_dirs + conf_files
 
-# Let's include redhat init scripts, despite build platform
-# but won't put them in /etc/init.d/ automatically anymore
-init_scripts = [ ('examples/init.d', ['distro/redhat/init.d/carbon-cache',
-                                      'distro/redhat/init.d/carbon-relay',
-                                      'distro/redhat/init.d/carbon-aggregator']) ]
-install_files += init_scripts
-
 
 setup(
   name='carbon',
