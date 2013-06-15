$NetBSD: patch-program_lib_Roundcube_rcube__mime.php,v 1.1 2013/06/15 16:08:09 taca Exp $

Fix from repository:
* commit db108e37793c7f8fc8ba11f00d0561d1f0bd32c0:
  Fix another text wrapping issue (wrong handling of long unwrappable lines)
* commit f031cb6c5e4fd3dcb7ea243d477825868d8ad17b:
 Fix performance regression in text wrapping function (#1489133) - don't use
 iconv here

--- program/lib/Roundcube/rcube_mime.php.orig	2013-05-16 18:06:36.000000000 +0000
+++ program/lib/Roundcube/rcube_mime.php
@@ -587,23 +587,20 @@ class rcube_mime
      */
     public static function wordwrap($string, $width=75, $break="\n", $cut=false, $charset=null, $wrap_quoted=true)
     {
-        if (!$charset) {
-            $charset = RCUBE_CHARSET;
-        }
+        // Note: Never try to use iconv instead of mbstring functions here
+        //       Iconv's substr/strlen are 100x slower (#1489113)
 
-        // detect available functions
-        $strlen_func  = function_exists('iconv_strlen') ? 'iconv_strlen' : 'mb_strlen';
-        $strpos_func  = function_exists('iconv_strpos') ? 'iconv_strpos' : 'mb_strpos';
-        $strrpos_func = function_exists('iconv_strrpos') ? 'iconv_strrpos' : 'mb_strrpos';
-        $substr_func  = function_exists('iconv_substr') ? 'iconv_substr' : 'mb_substr';
+        if ($charset && $charset != RCUBE_CHARSET && function_exists('mb_internal_encoding')) {
+            mb_internal_encoding($charset);
+        }
 
         // Convert \r\n to \n, this is our line-separator
         $string       = str_replace("\r\n", "\n", $string);
         $separator    = "\n"; // must be 1 character length
         $result       = array();
 
-        while (($stringLength = $strlen_func($string, $charset)) > 0) {
-            $breakPos = $strpos_func($string, $separator, 0, $charset);
+        while (($stringLength = mb_strlen($string)) > 0) {
+            $breakPos = mb_strpos($string, $separator, 0);
 
             // quoted line (do not wrap)
             if ($wrap_quoted && $string[0] == '>') {
@@ -612,7 +609,7 @@ class rcube_mime
                     $cutLength = null;
                 }
                 else {
-                    $subString = $substr_func($string, 0, $breakPos, $charset);
+                    $subString = mb_substr($string, 0, $breakPos);
                     $cutLength = $breakPos + 1;
                 }
             }
@@ -623,55 +620,54 @@ class rcube_mime
                     $cutLength = null;
                 }
                 else {
-                    $subString = $substr_func($string, 0, $breakPos, $charset);
+                    $subString = mb_substr($string, 0, $breakPos);
                     $cutLength = $breakPos + 1;
                 }
             }
             else {
-                $subString = $substr_func($string, 0, $width, $charset);
+                $subString = mb_substr($string, 0, $width);
 
                 // last line
                 if ($breakPos === false && $subString === $string) {
                     $cutLength = null;
                 }
                 else {
-                    $nextChar = $substr_func($string, $width, 1, $charset);
+                    $nextChar = mb_substr($string, $width, 1);
 
                     if ($nextChar === ' ' || $nextChar === $separator) {
-                        $afterNextChar = $substr_func($string, $width + 1, 1, $charset);
+                        $afterNextChar = mb_substr($string, $width + 1, 1);
 
                         if ($afterNextChar === false) {
                             $subString .= $nextChar;
                         }
 
-                        $cutLength = $strlen_func($subString, $charset) + 1;
+                        $cutLength = mb_strlen($subString) + 1;
                     }
                     else {
-                        if ($strrpos_func[0] == 'm') {
-                            $spacePos = $strrpos_func($subString, ' ', 0, $charset);
-                        }
-                        else {
-                            $spacePos = $strrpos_func($subString, ' ', $charset);
-                        }
+                        $spacePos = mb_strrpos($subString, ' ', 0);
 
                         if ($spacePos !== false) {
-                            $subString = $substr_func($subString, 0, $spacePos, $charset);
+                            $subString = mb_substr($subString, 0, $spacePos);
                             $cutLength = $spacePos + 1;
                         }
+                        else if ($cut === false && $breakPos === false) {
+                            $subString = $string;
+                            $cutLength = null;
+                        }
                         else if ($cut === false) {
-                            $spacePos = $strpos_func($string, ' ', 0, $charset);
+                            $spacePos = mb_strpos($string, ' ', 0);
 
                             if ($spacePos !== false && $spacePos < $breakPos) {
-                                $subString = $substr_func($string, 0, $spacePos, $charset);
+                                $subString = mb_substr($string, 0, $spacePos);
                                 $cutLength = $spacePos + 1;
                             }
                             else {
-                                $subString = $substr_func($string, 0, $breakPos, $charset);
+                                $subString = mb_substr($string, 0, $breakPos);
                                 $cutLength = $breakPos + 1;
                             }
                         }
                         else {
-                            $subString = $substr_func($subString, 0, $width, $charset);
+                            $subString = mb_substr($subString, 0, $width);
                             $cutLength = $width;
                         }
                     }
@@ -681,13 +677,17 @@ class rcube_mime
             $result[] = $subString;
 
             if ($cutLength !== null) {
-                $string = $substr_func($string, $cutLength, ($stringLength - $cutLength), $charset);
+                $string = mb_substr($string, $cutLength, ($stringLength - $cutLength));
             }
             else {
                 break;
             }
         }
 
+        if ($charset && $charset != RCUBE_CHARSET && function_exists('mb_internal_encoding')) {
+            mb_internal_encoding(RCUBE_CHARSET);
+        }
+
         return implode($break, $result);
     }
 
@@ -795,7 +795,7 @@ class rcube_mime
         }
 
         foreach ($file_paths as $fp) {
-            if (is_readable($fp)) {
+            if (@is_readable($fp)) {
                 $lines = file($fp, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
                 break;
             }
