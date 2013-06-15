$NetBSD: patch-program_lib_Roundcube_rcube__cache.php,v 1.1 2013/06/15 16:08:09 taca Exp $

Fix from repository:
* commit 72c8504b99fbd423651bab0180a044c489ca05cc:
  Fix bug where serialized strings were truncated in PDO::quote() (#1489142)

--- program/lib/Roundcube/rcube_cache.php.orig	2013-05-16 18:06:36.000000000 +0000
+++ program/lib/Roundcube/rcube_cache.php
@@ -145,7 +145,7 @@ class rcube_cache
      */
     function write($key, $data)
     {
-        return $this->write_record($key, $this->packed ? serialize($data) : $data);
+        return $this->write_record($key, $this->serialize($data));
     }
 
 
@@ -219,7 +219,7 @@ class rcube_cache
             if ($this->cache_changes[$key]) {
                 // Make sure we're not going to write unchanged data
                 // by comparing current md5 sum with the sum calculated on DB read
-                $data = $this->packed ? serialize($data) : $data;
+                $data = $this->serialize($data);
 
                 if (!$this->cache_sums[$key] || $this->cache_sums[$key] != md5($data)) {
                     $this->write_record($key, $data);
@@ -255,7 +255,7 @@ class rcube_cache
 
             if ($data) {
                 $md5sum = md5($data);
-                $data   = $this->packed ? unserialize($data) : $data;
+                $data   = $this->unserialize($data);
 
                 if ($nostore) {
                     return $data;
@@ -283,7 +283,7 @@ class rcube_cache
                 $key = substr($sql_arr['cache_key'], strlen($this->prefix)+1);
                 $md5sum = $sql_arr['data'] ? md5($sql_arr['data']) : null;
                 if ($sql_arr['data']) {
-                    $data = $this->packed ? unserialize($sql_arr['data']) : $sql_arr['data'];
+                    $data = $this->unserialize($sql_arr['data']);
                 }
 
                 if ($nostore) {
@@ -364,7 +364,6 @@ class rcube_cache
      * @param string  $key         Cache key name or pattern
      * @param boolean $prefix_mode Enable it to clear all keys starting
      *                             with prefix specified in $key
-     *
      */
     private function remove_record($key=null, $prefix_mode=false)
     {
