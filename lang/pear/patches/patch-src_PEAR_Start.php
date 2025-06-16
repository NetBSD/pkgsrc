$NetBSD: patch-src_PEAR_Start.php,v 1.1 2025/06/16 09:21:45 jperkin Exp $

Use pkgsrc layout.

--- src/PEAR/Start.php.orig	2025-06-11 14:08:51.952589560 +0000
+++ src/PEAR/Start.php
@@ -6,6 +6,7 @@ require_once 'phar://go-pear.phar/' . 'P
 require_once 'phar://go-pear.phar/' . 'PEAR/Common.php';
 class PEAR_Start extends PEAR
 {
+    var $destdir;
     var $bin_dir;
     var $data_dir;
     var $cfg_dir;
@@ -146,33 +147,19 @@ class PEAR_Start extends PEAR
                 }
             }
         } else {
-            $this->prefix = dirname(PHP_BINDIR);
-            $this->pear_conf = PEAR_CONFIG_SYSCONFDIR . '/pear.conf';
-            if ($this->getCurrentUser() != 'root') {
-                $this->prefix = $this->safeGetenv('HOME') . '/pear';
-                $this->pear_conf = $this->safeGetenv('HOME') . '.pearrc';
-            }
+            $this->destdir = getenv('DESTDIR');
+            $this->pear_conf = '@WRKSRC@/pear.conf';
+            $this->prefix = "@PREFIX@";
             $this->bin_dir   = '$prefix/bin';
-            $this->php_dir   = '$prefix/share/pear';
+            $this->php_dir   = '$prefix/@PHP_LIBDIR@';
             $this->temp_dir  = '/tmp/pear/install';
             $this->download_dir  = '/tmp/pear/install';
-            $this->doc_dir   = '$prefix/docs';
-            $this->www_dir   = '$prefix/www';
-            $this->cfg_dir   = '$prefix/cfg';
-            $this->data_dir  = '$prefix/data';
-            $this->test_dir  = '$prefix/tests';
-            $this->man_dir  = '$prefix/man';
-            // check if the user has installed PHP with PHP or GNU layout
-            if (@is_dir("$this->prefix/lib/php/.registry")) {
-                $this->php_dir = '$prefix/lib/php';
-            } elseif (@is_dir("$this->prefix/share/pear/lib/.registry")) {
-                $this->php_dir = '$prefix/share/pear/lib';
-                $this->doc_dir   = '$prefix/share/pear/docs';
-                $this->data_dir  = '$prefix/share/pear/data';
-                $this->test_dir  = '$prefix/share/pear/tests';
-            } elseif (@is_dir("$this->prefix/share/php/.registry")) {
-                $this->php_dir = '$prefix/share/php';
-            }
+            $this->doc_dir   = '$php_dir/doc';
+            $this->www_dir   = '$php_dir/www';
+            $this->cfg_dir   = '$php_dir/cfg';
+            $this->data_dir  = '$php_dir/data';
+            $this->test_dir  = '$php_dir/test';
+            $this->man_dir  = '$prefix/@PKGMANDIR@';
         }
     }
 
@@ -335,6 +322,7 @@ class PEAR_Start extends PEAR
         $install = &PEAR_Command::factory('install', $this->PEARConfig);
         print "Preparing to install...\n";
         $options = array(
+            'packagingroot' => $this->destdir,
             'nodeps' => true,
             'force' => true,
             'upgrade' => true,
@@ -355,7 +343,7 @@ class PEAR_Start extends PEAR
         }
 
         foreach ($this->config as $var) {
-            $dir = $this->$var;
+            $dir = ($this->destdir ? $this->destdir : '').$this->$var;
 
             if (!preg_match('/_dir\\z/', $var)) {
                 continue;
