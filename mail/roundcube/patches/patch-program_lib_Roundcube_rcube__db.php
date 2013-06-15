$NetBSD: patch-program_lib_Roundcube_rcube__db.php,v 1.1 2013/06/15 16:08:09 taca Exp $

Fix from repository:
* commit 72c8504b99fbd423651bab0180a044c489ca05cc:
  Fix bug where serialized strings were truncated in PDO::quote() (#1489142)
* commit ab05ee25c1d38c884790337796f7c941e28d36d9:
   Fix backward copat. with cached values serialized but not base64-encoded
   (#1489142)

--- program/lib/Roundcube/rcube_db.php.orig	2013-05-16 18:06:36.000000000 +0000
+++ program/lib/Roundcube/rcube_db.php
@@ -789,12 +789,19 @@ class rcube_db
     /**
      * Encodes non-UTF-8 characters in string/array/object (recursive)
      *
-     * @param mixed $input Data to fix
+     * @param mixed $input      Data to fix
+     * @param bool  $serialized Enable serialization
      *
      * @return mixed Properly UTF-8 encoded data
      */
-    public static function encode($input)
+    public static function encode($input, $serialized = false)
     {
+        // use Base64 encoding to workaround issues with invalid
+        // or null characters in serialized string (#1489142)
+        if ($serialized) {
+            return base64_encode(serialize($input));
+        }
+
         if (is_object($input)) {
             foreach (get_object_vars($input) as $idx => $value) {
                 $input->$idx = self::encode($value);
@@ -805,6 +812,7 @@ class rcube_db
             foreach ($input as $idx => $value) {
                 $input[$idx] = self::encode($value);
             }
+
             return $input;
         }
 
@@ -814,12 +822,24 @@ class rcube_db
     /**
      * Decodes encoded UTF-8 string/object/array (recursive)
      *
-     * @param mixed $input Input data
+     * @param mixed $input      Input data
+     * @param bool  $serialized Enable serialization
      *
      * @return mixed Decoded data
      */
-    public static function decode($input)
+    public static function decode($input, $serialized = false)
     {
+        // use Base64 encoding to workaround issues with invalid
+        // or null characters in serialized string (#1489142)
+        if ($serialized) {
+            // Keep backward compatybility where base64 wasn't used
+            if (strpos(substr($input, 0, 16), ':') !== false) {
+                return self::decode(@unserialize($input));
+            }
+
+            return @unserialize(base64_decode($input));
+        }
+
         if (is_object($input)) {
             foreach (get_object_vars($input) as $idx => $value) {
                 $input->$idx = self::decode($value);
