$NetBSD: patch-program_lib_Roundcube_rcube__config.php,v 1.1 2013/06/15 16:08:09 taca Exp $

Fix from repository:
* commit 55e60c6d85efa3e4b3679c8f9c0b97109ee31ca3:
  Fix legacy options handling 

--- program/lib/Roundcube/rcube_config.php.orig	2013-05-16 18:06:36.000000000 +0000
+++ program/lib/Roundcube/rcube_config.php
@@ -174,7 +174,7 @@ class rcube_config
             ob_end_clean();
 
             if (is_array($rcmail_config)) {
-                $this->prop = array_merge($this->prop, $rcmail_config, $this->userprefs);
+                $this->merge($rcmail_config);
                 return true;
             }
         }
@@ -195,9 +195,6 @@ class rcube_config
         if (isset($this->prop[$name])) {
             $result = $this->prop[$name];
         }
-        else if (isset($this->legacy_props[$name])) {
-            return $this->get($this->legacy_props[$name], $def);
-        }
         else {
             $result = $def;
         }
@@ -241,6 +238,7 @@ class rcube_config
     public function merge($prefs)
     {
         $this->prop = array_merge($this->prop, $prefs, $this->userprefs);
+        $this->fix_legacy_props();
     }
 
 
@@ -273,6 +271,8 @@ class rcube_config
         $this->userprefs = $prefs;
         $this->prop      = array_merge($this->prop, $prefs);
 
+        $this->fix_legacy_props();
+
         // override timezone settings with client values
         if ($this->prop['timezone'] == 'auto') {
             $this->prop['_timezone_value'] = isset($_SESSION['timezone']) ? $this->client_timezone() : $this->prop['_timezone_value'];
@@ -435,4 +435,18 @@ class rcube_config
         return date_default_timezone_get();
     }
 
+    /**
+     * Convert legacy options into new ones
+     */
+    private function fix_legacy_props()
+    {
+        foreach ($this->legacy_props as $new => $old) {
+            if (isset($this->prop[$old])) {
+                if (!isset($this->prop[$new])) {
+                    $this->prop[$new] = $this->prop[$old];
+                }
+                unset($this->prop[$old]);
+            }
+        }
+    }
 }
