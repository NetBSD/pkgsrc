$NetBSD: patch-plugins_zipdownload_zipdownload.php,v 1.1 2013/06/15 16:08:09 taca Exp $

Fix from repository:
* commit 057b9e3e7f5bd1707e72812b1e5f977face0baed,
	 b9139f9f98fe994142dd3e050dac1e6ec9a24309:
   Fix zipdownload plugin issue with filenames charset (#1489156)

--- plugins/zipdownload/zipdownload.php.orig	2013-05-16 18:06:35.000000000 +0000
+++ plugins/zipdownload/zipdownload.php
@@ -105,7 +105,7 @@ class zipdownload extends rcube_plugin
 		foreach ($message->attachments as $part) {
 			$pid = $part->mime_id;
 			$part = $message->mime_parts[$pid];
-			$disp_name = $this->_convert_filename($part->filename, $part->charset);
+			$disp_name = $this->_convert_filename($part->filename);
 
 			if ($part->body) {
 				$orig_message_raw = $part->body;
@@ -258,9 +258,9 @@ class zipdownload extends rcube_plugin
 	/**
 	 * Helper function to convert filenames to the configured charset
 	 */
-	private function _convert_filename($str, $from = RCMAIL_CHARSET)
+	private function _convert_filename($str)
 	{
-        $str = rcube_charset::convert($str, $from == '' ? RCUBE_CHARSET : $from, $this->charset);
+        $str = rcube_charset::convert($str, RCUBE_CHARSET, $this->charset);
 
 		return strtr($str, array(':'=>'', '/'=>'-'));
 	}
