$NetBSD: patch-objects_functionsExec.php,v 1.1 2025/03/03 15:21:05 manu Exp $

Implement getDirSize in pure PHP

This avoids starting an external program, and make the code
more compatible. For instnace, BSD du comand does not have a -b
option.

But the function should probably be moved in another file,
objects/functionsExec.php being dedicated to running external
programs.

From upstream https://github.com/WWBN/AVideo/pull/9907

diff --git a/objects/functionsExec.php b/objects/functionsExec.php
index 23c55f8dd2de..b0b9af6e30cb 100644
--- ./objects/functionsExec.php.orig
+++ ./objects/functionsExec.php
@@ -120,35 +120,16 @@ function getDirSize($dir, $forceNew = false)
 
     _error_log("getDirSize: start {$dir}");
 
-    if (isWindowsServer()) {
-        $return = foldersize($dir);
-        $_getDirSize[$dir] = $return;
-        return $return;
-    } else {
-        $command = "du -sb {$dir}";
-        exec($command . " < /dev/null 2>&1", $output, $return_val);
-        if ($return_val !== 0) {
-            _error_log("getDirSize: ERROR ON Command {$command}");
-            $return = 0;
-            $_getDirSize[$dir] = $return;
-            return $return;
-        } else {
-            if (!empty($output[0])) {
-                preg_match("/^([0-9]+).*/", $output[0], $matches);
-            }
-            if (!empty($matches[1])) {
-                _error_log("getDirSize: found {$matches[1]} from - {$output[0]}");
-                $return = intval($matches[1]);
-                $_getDirSize[$dir] = $return;
-                return $return;
-            }
-
-            _error_log("getDirSize: ERROR on pregmatch {$output[0]}");
-            $return = 0;
-            $_getDirSize[$dir] = $return;
-            return $return;
+    $return = 0;
+    $rdi = new RecursiveDirectoryIterator($dir);
+    $rii = new RecursiveIteratorIterator($rdi);
+    foreach ($rii as $file) {
+        if (is_file($file)) {
+            $return += $file->getSize();
         }
     }
+
+    return $return;
 }
 
 function rrmdirCommandLine($dir, $async = false)
