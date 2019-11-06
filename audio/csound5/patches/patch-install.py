$NetBSD: patch-install.py,v 1.4 2019/11/06 11:56:56 mrg Exp $

python 3.x support

don't fake-conflict with csound6.

--- install.py.orig	2013-01-07 04:49:35.000000000 -0800
+++ install.py	2019-11-06 03:43:25.554498784 -0800
@@ -3,7 +3,6 @@
 import sys
 import os
 import re
-import md5
 import time
 
 # get Python version
@@ -28,13 +27,14 @@
              'scsort', 'extract', 'cs', 'csb64enc', 'makecsd', 'scot']
 
 exeFiles2 = ['brkpt', 'linseg', 'tabdes']
+exeFiles2 = []
 
 docFiles = ['COPYING', 'ChangeLog', 'INSTALL', 'readme-csound5.txt']
 
 # -----------------------------------------------------------------------------
 
-print 'Csound5 Linux installer by Istvan Varga'
-print ''
+print('Csound5 Linux installer by Istvan Varga')
+print('')
 
 prefix = '/usr/local'
 instDir = '/'
@@ -47,14 +47,14 @@
 word64Suffix = ''
 
 def printUsage():
-    print "Usage: ./install.py [options...]"
-    print "Allowed options are:"
-    print "    --prefix=DIR    base directory (default: /usr/local)"
-    print "    --instdir=DIR   installation root directory (default: /)"
-    print "    --vimdir=DIR    VIM runtime directory (default: none)"
-    print "    --word64        install libraries to 'lib64' instead of 'lib'"
-    print "    --help          print this message"
-    print ""
+    print("Usage: ./install.py [options...]")
+    print("Allowed options are:")
+    print("    --prefix=DIR    base directory (default: /usr/local)")
+    print("    --instdir=DIR   installation root directory (default: /)")
+    print("    --vimdir=DIR    VIM runtime directory (default: none)")
+    print("    --word64        install libraries to 'lib64' instead of 'lib'")
+    print("    --help          print this message")
+    print("")
 
 # parse command line options
 
@@ -73,10 +73,10 @@
             word64Suffix = '64'
         else:
             printUsage()
-            print 'Error: unknown option: %s' % sys.argv[i]
+            print('Error: unknown option: %s' % sys.argv[i])
             raise SystemExit(1)
 
-print prefix
+print(prefix)
 
 # concatenates a list of directory names,
 # and returns full path without a trailing '/'
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
@@ -128,7 +128,7 @@
 
 def makeDir(dirName):
     try:
-        os.makedirs(concatPath([instDir, dirName]), 0755)
+        os.makedirs(concatPath([instDir, dirName]), 0o755)
     except:
         pass
 
@@ -158,9 +158,9 @@
         err = runCmd(['strip', stripMode, fullName])
     if err == 0:
         addMD5(fullName, fileName)
-        print '  %s' % fileName
+        print('  %s' % fileName)
     else:
-        print ' *** error copying %s' % fileName
+        print(' *** error copying %s' % fileName)
     return err
 
 def installFile(src, dst):
@@ -195,9 +195,9 @@
             addMD5(concatPath([instDir, src]), linkName)
         else:
             addMD5(concatPath([instDir, linkName]), linkName)
-        print '  %s' % linkName
+        print('  %s' % linkName)
     else:
-        print ' *** error copying %s' % linkName
+        print(' *** error copying %s' % linkName)
     return err
 
 def findFiles(dir, pat):
@@ -218,30 +218,30 @@
 
 makeDir(concatPath([binDir]))
 installedBinaries = findFiles(concatPath([instDir, binDir]), '.+')
-if ('csound' in installedBinaries) or ('csound64' in installedBinaries):
+if ('csound5' in installedBinaries) or ('csound64' in installedBinaries):
     if 'uninstall-csound5' in installedBinaries:
-        print ' *** WARNING: found an already existing installation of Csound'
+        print(' *** WARNING: found an already existing installation of Csound')
         tmp = ''
         while (tmp != 'yes\n') and (tmp != 'no\n'):
             sys.__stderr__.write(
                 ' *** Uninstall it ? Type \'yes\', or \'no\' to quit: ')
             tmp = sys.__stdin__.readline()
         if tmp != 'yes\n':
-            print ' *** Csound installation has been aborted'
-            print ''
+            print(' *** Csound installation has been aborted')
+            print('')
             raise SystemExit(1)
-        print ' --- Removing old Csound installation...'
+        print(' --- Removing old Csound installation...')
         runCmd([concatPath([instDir, binDir, 'uninstall-csound5'])])
-        print ''
+        print('')
     else:
-        print ' *** Error: an already existing installation of Csound was found'
-        print ' *** Try removing it first, and then run this script again'
-        print ''
+        print(' *** Error: an already existing installation of Csound was found')
+        print(' *** Try removing it first, and then run this script again')
+        print('')
         raise SystemExit(1)
 
 # copy binaries
 
-print ' === Installing executables ==='
+print(' === Installing executables ===')
 for i in exeFiles1:
     if findFiles('.', i).__len__() > 0:
         err = installXFile('--strip-unneeded', i, binDir)
@@ -253,7 +253,7 @@
 
 # copy libraries
 
-print ' === Installing libraries ==='
+print(' === Installing libraries ===')
 libList = findFiles('.', 'libcsound\\.a')
 libList += findFiles('.', 'libcsound64\\.a')
 libList += findFiles('.', 'libcsound\\.so\\..+')
@@ -280,7 +280,7 @@
 
 # copy plugin libraries
 
-print ' === Installing plugins ==='
+print(' === Installing plugins ===')
 if not useDouble:
     pluginDir = pluginDir32
 else:
@@ -297,13 +297,13 @@
 
 # copy header files
 
-print ' === Installing header files ==='
+print(' === Installing header files ===')
 err = installFiles(headerFiles, includeDir)
 installErrors = installErrors or err
 
 # copy language interfaces
 
-print ' === Installing language interfaces ==='
+print(' === Installing language interfaces ===')
 wrapperList = [['csnd\\.py', '0', pythonDir],
                ['loris\\.py', '0', pythonDir],
                ['CsoundVST\\.py', '0', pythonDir],
@@ -327,7 +327,7 @@
 
 # copy XMG files
 
-print ' === Installing Localisation files ==='
+print(' === Installing Localisation files ===')
 xmgList = findFiles('.', '.+\\.xmg')
 if xmgList.__len__() > 0:
     err = installFiles(xmgList, xmgDir)
@@ -341,34 +341,34 @@
     err = runCmd(['install', '-p', '-m', '0644', src, fileName])
     if err == 0:
         addMD5(fileName, fileName)
-        print '  %s' % fileName
+        print('  %s' % fileName)
     else:
-        print ' *** error copying %s' % fileName
+        print(' *** error copying %s' % fileName)
         installErrors = installErrors or err
 
 # Copy documentation
 
-print ' === Installing documentation ==='
+print(' === Installing documentation ===')
 err = installFiles(docFiles, docDir)
 installErrors = installErrors or err
 
 # copy Tcl/Tk files
 
-print ' === Installing Tcl/Tk modules and scripts ==='
+print(' === Installing Tcl/Tk modules and scripts ===')
 if findFiles('.', 'tclcsound\\.so').__len__() > 0:
     err = installXFile('--strip-unneeded', 'tclcsound.so', tclDir)
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
 
 if '%s/libstk.so' % pluginDir in fileList:
-    print ' === Installing STK raw wave files ==='
+    print(' === Installing STK raw wave files ===')
     rawWaveFiles = []
     for fName in os.listdir('./Opcodes/stk/rawwaves'):
         if re.match('^.*\.raw$', fName) != None:
@@ -397,11 +397,11 @@
 except:
     pdDir = ''
 if pdDir != '':
-    print ' === Installing csoundapi~ PD object ==='
+    print(' === Installing csoundapi~ PD object ===')
     err = installXFile('--strip-unneeded', 'csoundapi~.pd_linux', pdDir)
     if err == 0:
         try:
-            os.chmod(concatPath([instDir, pdDir, 'csoundapi~.pd_linux']), 0644)
+            os.chmod(concatPath([instDir, pdDir, 'csoundapi~.pd_linux']), 0o644)
         except:
             err = -1
     installErrors = installErrors or err
@@ -409,7 +409,7 @@
 # copy VIM files if enabled
 
 if vimDir != '':
-    print ' === Installing VIM syntax files ==='
+    print(' === Installing VIM syntax files ===')
     err = installXFile('', 'installer/misc/vim/cshelp', binDir)
     installErrors = installErrors or err
     err = installFile('installer/misc/vim/csound.vim',
@@ -420,71 +420,31 @@
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
 
-print ''
+print('')
 
 # check for errors
 
 if installErrors:
-    print ' *** Errors occured during installation, deleting files...'
+    print(' *** Errors occured during installation, deleting files...')
     for i in fileList:
         try:
             os.remove(concatPath([instDir, i]))
         except:
             pass
 else:
-    print 'Csound installation has been successfully completed.'
-    print 'Before running Csound, make sure that the following environment'
-    print 'variables are set:'
+    print('Csound installation has been successfully completed.')
+    print('Before running Csound, make sure that the following environment')
+    print('variables are set:')
     if not useDouble:
-        print '  OPCODEDIR=%s' % pluginDir32
+        print('  OPCODEDIR=%s' % pluginDir32)
     else:
-        print '  OPCODEDIR64=%s' % pluginDir64
-    print '  CSSTRNGS=%s' % xmgDir
+        print('  OPCODEDIR64=%s' % pluginDir64)
+    print('  CSSTRNGS=%s' % xmgDir)
     if '%s/libstk.so' % pluginDir in fileList:
-        print '  RAWWAVE_PATH=%s' % rawWaveDir
-    print 'Csound can be uninstalled by running %s/uninstall-csound5' % binDir
-
-if os.getuid() == 0:
-    runCmd(['/sbin/ldconfig'])
+        print('  RAWWAVE_PATH=%s' % rawWaveDir)
+    print('Csound can be uninstalled by running %s/uninstall-csound5' % binDir)
 
-print ''
+print('')
 
