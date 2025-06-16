$NetBSD: patch-src_PEAR_Start_CLI.php,v 1.1 2025/06/16 09:21:45 jperkin Exp $

Avoid unnecessary code paths and support unattended installs.

--- src/PEAR/Start/CLI.php.orig	2025-06-11 10:09:02.740661641 +0000
+++ src/PEAR/Start/CLI.php
@@ -62,7 +62,6 @@ class PEAR_Start_CLI extends PEAR_Start
         if (PEAR::isError($err = $this->locatePackagesToInstall())) {
             return $err;
         }
-        $this->startupQuestion();
         $this->setupTempStuff();
         $this->getInstallLocations();
         $this->displayPreamble();
@@ -123,7 +122,7 @@ accept these locations.
             }
 
             print "\n$this->first-$this->last, 'all' or Enter to continue: ";
-            $tmp = trim(fgets($this->tty, 1024));
+            $tmp = '';
             if (empty($tmp)) {
                 if (OS_WINDOWS && !$this->validPHPBin) {
                     echo "**ERROR**
@@ -339,7 +338,7 @@ your scripts, you will have problems get
 
             if ($php_ini = $this->getPhpiniPath()) {
                 print "\n\nWould you like to alter php.ini <$php_ini>? [Y/n] : ";
-                $alter_phpini = !stristr(fgets($this->tty, 1024), "n");
+                $alter_phpini = false;
                 if ($alter_phpini) {
                     $this->alterPhpIni($php_ini);
                 } else {
@@ -364,7 +363,6 @@ Currently used php.ini (guess) : $php_in
 ";
 
             print "Press Enter to continue: ";
-            fgets($this->tty, 1024);
         }
 
         $pear_cmd = $this->bin_dir . DIRECTORY_SEPARATOR . 'pear';
