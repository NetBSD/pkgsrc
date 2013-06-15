$NetBSD: patch-program_lib_Roundcube_rcube__imap__cache.php,v 1.1 2013/06/15 16:08:09 taca Exp $

Fix from repository:
* commit 6213c6a6e18848d861f2add83bdb69a1de3f5956:
  Fix removing flags from serialized object before saving it in DB
Fix from repository:
* commit 72c8504b99fbd423651bab0180a044c489ca05cc:
  Fix bug where serialized strings were truncated in PDO::quote() (#1489142)

--- program/lib/Roundcube/rcube_imap_cache.php.orig	2013-05-16 18:06:36.000000000 +0000
+++ program/lib/Roundcube/rcube_imap_cache.php
@@ -407,8 +407,8 @@ class rcube_imap_cache
             return;
         }
 
-        $msg   = serialize($this->db->encode(clone $message));
         $flags = 0;
+        $msg   = clone $message;
 
         if (!empty($message->flags)) {
             foreach ($this->flags as $idx => $flag) {
@@ -417,7 +417,9 @@ class rcube_imap_cache
                 }
             }
         }
+
         unset($msg->flags);
+        $msg = $this->db->encode($msg, true);
 
         // update cache record (even if it exists, the update
         // here will work as select, assume row exist if affected_rows=0)
@@ -639,7 +641,7 @@ class rcube_imap_cache
 
         if ($sql_arr = $this->db->fetch_assoc($sql_result)) {
             $data  = explode('@', $sql_arr['data']);
-            $index = @unserialize($data[0]);
+            $index = $this->db->decode($data[0], true);
             unset($data[0]);
 
             if (empty($index)) {
@@ -676,7 +678,7 @@ class rcube_imap_cache
 
         if ($sql_arr = $this->db->fetch_assoc($sql_result)) {
             $data   = explode('@', $sql_arr['data']);
-            $thread = @unserialize($data[0]);
+            $thread = $this->db->decode($data[0], true);
             unset($data[0]);
 
             if (empty($thread)) {
@@ -702,7 +704,7 @@ class rcube_imap_cache
         $data, $mbox_data = array(), $exists = false, $modseq = null)
     {
         $data = array(
-            serialize($data),
+            $this->db->encode($data, true),
             $sort_field,
             (int) $this->skip_deleted,
             (int) $mbox_data['UIDVALIDITY'],
@@ -735,7 +737,7 @@ class rcube_imap_cache
     private function add_thread_row($mailbox, $data, $mbox_data = array(), $exists = false)
     {
         $data = array(
-            serialize($data),
+            $this->db->encode($data, true),
             (int) $this->skip_deleted,
             (int) $mbox_data['UIDVALIDITY'],
             (int) $mbox_data['UIDNEXT'],
@@ -1067,7 +1069,7 @@ class rcube_imap_cache
      */
     private function build_message($sql_arr)
     {
-        $message = $this->db->decode(unserialize($sql_arr['data']));
+        $message = $this->db->decode($sql_arr['data'], true);
 
         if ($message) {
             $message->flags = array();
