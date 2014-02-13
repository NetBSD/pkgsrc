$NetBSD: patch-install.py,v 1.2 2014/02/13 10:10:06 mrg Exp $

* adjust installation layout to same as SCons.
* kill uninstaller and md5sum for it.
* kill ldconfig

--- install.py.orig	2013-01-07 04:49:35.000000000 -0800
+++ install.py	2014-02-12 21:10:18.000000000 -0800
@@ -3,7 +3,6 @@
 import sys
 import os
 import re
-import md5
 import time
 
 # get Python version
@@ -28,6 +27,7 @@
              'scsort', 'extract', 'cs', 'csb64enc', 'makecsd', 'scot']
 
 exeFiles2 = ['brkpt', 'linseg', 'tabdes']
+exeFiles2 = []
 
 docFiles = ['COPYING', 'ChangeLog', 'INSTALL', 'readme-csound5.txt']
 
@@ -96,15 +96,15 @@
     return s
 
 # frontends
-binDir      = concatPath([prefix, '/bin'])
+binDir      = concatPath([prefix, '/lib/csound5'])
 # Csound API header files
-includeDir  = concatPath([prefix, '/include/csound'])
+includeDir  = concatPath([prefix, '/include/csound5'])
 # Csound API libraries
-libDir      = concatPath([prefix, '/lib' + word64Suffix])
+libDir      = concatPath([prefix, '/lib/csound5' + word64Suffix])
 # single precision plugin libraries
-pluginDir32 = concatPath([libDir, '/csound/plugins'])
+pluginDir32 = concatPath([libDir, '/plugins'])
 # double precision plugin libraries
-pluginDir64 = concatPath([libDir, '/csound/plugins64'])
+pluginDir64 = concatPath([libDir, '/plugins64'])
 # XMG files
 xmgDir      = concatPath([prefix, '/share/locale'])
 # documentation
@@ -360,9 +360,9 @@
     installErrors = installErrors or err
     err = installFile('frontends/tclcsound/command_summary.txt', tclDir)
     installErrors = installErrors or err
-err = installFile('nsliders.tk', tclDir)
-installErrors = installErrors or err
-err = installXFile('', 'matrix.tk', binDir)
+    err = installFile('nsliders.tk', tclDir)
+    installErrors = installErrors or err
+    err = installXFile('', 'matrix.tk', binDir)
 installErrors = installErrors or err
 
 # copy STK raw wave files
@@ -420,43 +420,6 @@
                           '%s/%s' % (vimDir, 'syntax'))
         installErrors = installErrors or err
 
-# create uninstall script
-
-print ' === Installing uninstall script ==='
-fileList += [concatPath([prefix, md5Name])]
-fileList += [concatPath([binDir, 'uninstall-csound5'])]
-try:
-    f = open(concatPath([instDir, binDir, 'uninstall-csound5']), 'w')
-    print >> f, '#!/bin/sh'
-    print >> f, ''
-    for i in fileList:
-        print >> f, 'rm -f "%s"' % i
-    print >> f, ''
-    print >> f, '/sbin/ldconfig > /dev/null 2> /dev/null'
-    print >> f, ''
-    f.close()
-    os.chmod(concatPath([instDir, binDir, 'uninstall-csound5']), 0755)
-    addMD5(concatPath([instDir, binDir, 'uninstall-csound5']),
-           concatPath([binDir, 'uninstall-csound5']))
-    print '  %s' % concatPath([binDir, 'uninstall-csound5'])
-except:
-    print ' *** Error creating uninstall script'
-    installErrors = 1
-
-# save MD5 checksums
-
-print ' === Installing MD5 checksums ==='
-try:
-    f = open(concatPath([instDir, prefix, md5Name]), 'w')
-    print >> f, md5List,
-    f.close()
-    os.chmod(concatPath([instDir, prefix, md5Name]), 0644)
-    print '  %s' % concatPath([prefix, md5Name])
-except:
-    print ' *** Error installing MD5 checksums'
-    installErrors = 1
-
-    
 # -----------------------------------------------------------------------------
 
 print ''
@@ -483,8 +446,5 @@
         print '  RAWWAVE_PATH=%s' % rawWaveDir
     print 'Csound can be uninstalled by running %s/uninstall-csound5' % binDir
 
-if os.getuid() == 0:
-    runCmd(['/sbin/ldconfig'])
-
 print ''
 
