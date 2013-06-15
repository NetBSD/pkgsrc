$NetBSD: patch-program_lib_Roundcube_rcube__imap.php,v 1.1 2013/06/15 16:08:09 taca Exp $

Fix from repository:
* commit 35b0a75f72ef1c7c83bf2ad8ba01f6ac1a444122:
  Fix default sorting of threaded list when THREAD=REFS isn't supported.

--- program/lib/Roundcube/rcube_imap.php.orig	2013-05-16 18:06:36.000000000 +0000
+++ program/lib/Roundcube/rcube_imap.php
@@ -1336,17 +1336,16 @@ class rcube_imap extends rcube_storage
         // THREAD=REFERENCES:     sorting by sent date of root message
         // THREAD=REFS:           sorting by the most recent date in each thread
 
-        if ($this->sort_field && ($this->sort_field != 'date' || $this->get_capability('THREAD') != 'REFS')) {
-            $index = $this->index_direct($this->folder, $this->sort_field, $this->sort_order, false);
+        if ($this->get_capability('THREAD') != 'REFS') {
+            $sortby = $this->sort_field ? $this->sort_field : 'date';
+            $index  = $this->index_direct($this->folder, $sortby, $this->sort_order, false);
 
             if (!$index->is_empty()) {
                 $threads->sort($index);
             }
         }
-        else {
-            if ($this->sort_order != $threads->get_parameters('ORDER')) {
-                $threads->revert();
-            }
+        else if ($this->sort_order != $threads->get_parameters('ORDER')) {
+            $threads->revert();
         }
     }
 
