$NetBSD: patch-install.py,v 1.1 2011/09/07 12:42:02 obache Exp $

* adjust installation layout to same as SCons.
* kill uninstaller and md5sum for it.
* kill ldconfig

--- install.py.orig	2006-03-15 15:20:59.000000000 +0000
+++ install.py
@@ -3,7 +3,6 @@
 import sys
 import os
 import re
-import md5
 import time
 
 # get Python version
@@ -25,7 +24,7 @@ exeFiles1 = ['csound', 'CsoundVST', 'cst
              'pvlook', 'scale', 'sndinfo', 'srconv',
              'scsort', 'extract', 'cs', 'csb64enc', 'makecsd', 'scot']
 
-exeFiles2 = ['brkpt', 'linseg', 'tabdes']
+exeFiles2 = []
 
 docFiles = ['COPYING', 'ChangeLog', 'INSTALL', 'readme-csound5.txt']
 
@@ -88,15 +87,15 @@ def concatPath(lst):
     return s
 
 # frontends
-binDir      = concatPath([prefix, '/bin'])
+binDir      = concatPath([prefix, '/lib/csound5'])
 # Csound API header files
-includeDir  = concatPath([prefix, '/include/csound'])
+includeDir  = concatPath([prefix, '/include/csound5'])
 # Csound API libraries
-libDir      = concatPath([prefix, '/lib'])
+libDir      = concatPath([prefix, '/lib/csound5'])
 # single precision plugin libraries
-pluginDir32 = concatPath([libDir, '/csound/plugins'])
+pluginDir32 = concatPath([libDir, '/plugins'])
 # double precision plugin libraries
-pluginDir64 = concatPath([libDir, '/csound/plugins64'])
+pluginDir64 = concatPath([libDir, '/plugins64'])
 # XMG files
 xmgDir      = concatPath([prefix, '/share/csound/xmg'])
 # documentation
@@ -317,7 +316,7 @@ installErrors = installErrors or err
 print ' === Installing Tcl/Tk modules and scripts ==='
 if findFiles('.', 'tclcsound\\.so').__len__() > 0:
     err = installXFile('--strip-unneeded', 'tclcsound.so', tclDir)
-err = installFile('nsliders.tk', tclDir)
+    err = installFile('nsliders.tk', tclDir)
 installErrors = installErrors or err
 
 # copy STK raw wave files
@@ -375,42 +374,6 @@ if vimDir != '':
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
 # -----------------------------------------------------------------------------
 
 print ''
@@ -437,8 +400,5 @@ else:
         print '  RAWWAVE_PATH=%s' % rawWaveDir
     print 'Csound can be uninstalled by running %s/uninstall-csound5' % binDir
 
-if os.getuid() == 0:
-    runCmd(['/sbin/ldconfig'])
-
 print ''
 
