$NetBSD: patch-PEAR_REST.php,v 1.1 2011/05/16 13:05:01 taca Exp $

* Update to r309592 in PEAR's repository, fixing CVE-2011-1144.

--- PEAR/REST.php.orig	2011-02-28 17:48:36.000000000 +0000
+++ PEAR/REST.php
@@ -102,7 +102,7 @@ class PEAR_REST
                 // reset the age of the cache if the server says it was unmodified
                 $result = $this->saveCache($url, $ret, null, true, $cacheId);
                 if (PEAR::isError($result)) {
-                    return PEAR::raiseErro($result->getMessage());
+                    return PEAR::raiseError($result->getMessage());
                 }
             }
 
@@ -122,7 +122,7 @@ class PEAR_REST
         if ($forcestring) {
             $result = $this->saveCache($url, $content, $lastmodified, false, $cacheId);
             if (PEAR::isError($result)) {
-                return PEAR::raiseErro($result->getMessage());
+                return PEAR::raiseError($result->getMessage());
             }
 
             return $content;
@@ -162,7 +162,7 @@ class PEAR_REST
 
         $result = $this->saveCache($url, $content, $lastmodified, false, $cacheId);
         if (PEAR::isError($result)) {
-            return PEAR::raiseErro($result->getMessage());
+            return PEAR::raiseError($result->getMessage());
         }
 
         return $content;
@@ -228,59 +228,75 @@ class PEAR_REST
         $cacheidfile = $d . 'rest.cacheid';
         $cachefile   = $d . 'rest.cachefile';
 
+        if (!is_dir($cache_dir)) {
+            if (System::mkdir(array('-p', $cache_dir)) === false) {
+              return PEAR::raiseError("The value of config option cache_dir ($cache_dir) is not a directory and attempts to create the directory failed.");
+            }
+        }
+
         if ($cacheid === null && $nochange) {
             $cacheid = unserialize(implode('', file($cacheidfile)));
         }
 
-        if (is_link($cacheidfile)) {
-            return PEAR::raiseError('SECURITY ERROR: Will not write to ' . $cacheidfile . ' as it is symlinked to ' . readlink($cacheidfile) . ' - Possible symlink attack');
-        }
+        $idData = serialize(array(
+            'age'        => time(),
+            'lastChange' => ($nochange ? $cacheid['lastChange'] : $lastmodified),
+        ));
 
-        if (is_link($cachefile)) {
-            return PEAR::raiseError('SECURITY ERROR: Will not write to ' . $cacheidfile . ' as it is symlinked to ' . readlink($cacheidfile) . ' - Possible symlink attack');
+        $result = $this->saveCacheFile($cacheidfile, $idData);
+        if (PEAR::isError($result)) {
+            return $result;
+        } elseif ($nochange) {
+            return true;
         }
 
-        $cacheidfile_fp = @fopen($cacheidfile, 'wb');
-        if (!$cacheidfile_fp) {
-            if (is_dir($cache_dir)) {
-                return PEAR::raiseError("The value of config option cache_dir ($cache_dir) is not a directory. ");
+        $result = $this->saveCacheFile($cachefile, serialize($contents));
+        if (PEAR::isError($result)) {
+            if (file_exists($cacheidfile)) {
+              @unlink($cacheidfile);
             }
 
-            System::mkdir(array('-p', $cache_dir));
-            $cacheidfile_fp = @fopen($cacheidfile, 'wb');
-            if (!$cacheidfile_fp) {
-                return PEAR::raiseError("Could not open $cacheidfile for writing.");
-            }
+            return $result;
         }
 
-        if ($nochange) {
-            fwrite($cacheidfile_fp, serialize(array(
-                'age'        => time(),
-                'lastChange' => $cacheid['lastChange'],
-                ))
-            );
-
-            fclose($cacheidfile_fp);
-            return true;
-        }
+        return true;
+    }
 
-        fwrite($cacheidfile_fp, serialize(array(
-            'age'        => time(),
-            'lastChange' => $lastmodified,
-            ))
-        );
-        fclose($cacheidfile_fp);
+    function saveCacheFile($file, $contents)
+    {
+        $len = strlen($contents);
 
-        $cachefile_fp = @fopen($cachefile, 'wb');
-        if (!$cachefile_fp) {
-            if (file_exists($cacheidfile)) {
-                @unlink($cacheidfile);
+        $cachefile_fp = @fopen($file, 'xb'); // x is the O_CREAT|O_EXCL mode
+        if ($cachefile_fp !== false) { // create file
+            if (fwrite($cachefile_fp, $contents, $len) < $len) {
+                fclose($cachefile_fp);
+                return PEAR::raiseError("Could not write $file.");
+            }
+        } else { // update file
+            $cachefile_lstat = lstat($file);
+            $cachefile_fp = @fopen($file, 'wb');
+            if (!$cachefile_fp) {
+                return PEAR::raiseError("Could not open $file for writing.");
+            }
+
+            $cachefile_fstat = fstat($cachefile_fp);
+            if (
+              $cachefile_lstat['mode'] == $cachefile_fstat['mode'] &&
+              $cachefile_lstat['ino']  == $cachefile_fstat['ino'] &&
+              $cachefile_lstat['dev']  == $cachefile_fstat['dev'] &&
+              $cachefile_fstat['nlink'] === 1
+            ) {
+                if (fwrite($cachefile_fp, $contents, $len) < $len) {
+                    fclose($cachefile_fp);
+                    return PEAR::raiseError("Could not write $file.");
+                }
+            } else {
+                fclose($cachefile_fp);
+                $link = function_exists('readlink') ? readlink($file) : $file;
+                return PEAR::raiseError('SECURITY ERROR: Will not write to ' . $file . ' as it is symlinked to ' . $link . ' - Possible symlink attack');
             }
-
-            return PEAR::raiseError("Could not open $cacheidfile for writing.");
         }
 
-        fwrite($cachefile_fp, serialize($contents));
         fclose($cachefile_fp);
         return true;
     }
