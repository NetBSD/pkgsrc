$NetBSD: patch-program_steps_mail_func.inc,v 1.1 2013/06/15 16:08:09 taca Exp $

Fix from repository:
* commit db108e37793c7f8fc8ba11f00d0561d1f0bd32c0:
  Fix another text wrapping issue (wrong handling of long unwrappable lines)
* commit f5fac810dd2b9276994585789cc68f71c4cd4cd3:
  Fix PHP warning when responding to a message with many Return-Path headers
  (#1489136)

--- program/steps/mail/func.inc.orig	2013-05-16 18:06:36.000000000 +0000
+++ program/steps/mail/func.inc
@@ -1532,11 +1532,11 @@ function rcmail_address_string($input, $
 /**
  * Wrap text to a given number of characters per line
  * but respect the mail quotation of replies messages (>).
- * Finally add another quotation level by prpending the lines
+ * Finally add another quotation level by prepending the lines
  * with >
  *
  * @param string Text to wrap
- * @param int The line width
+ * @param int    The line width
  * @return string The wrapped text
  */
 function rcmail_wrap_and_quote($text, $length = 72)
@@ -1552,7 +1552,7 @@ function rcmail_wrap_and_quote($text, $l
       $line = '>' . rtrim($line);
     else if (mb_strlen($line) > $max) {
       $newline = '';
-      foreach(explode("\n", rc_wordwrap($line, $length - 2)) as $l) {
+      foreach (explode("\n", rc_wordwrap($line, $length - 2)) as $l) {
         if (strlen($l))
           $newline .= '> ' . $l . "\n";
         else
@@ -1803,9 +1803,12 @@ function rcmail_identity_select($MESSAGE
     // Try Return-Path
     if ($from_idx === null && ($return_path = $MESSAGE->headers->others['return-path'])) {
         foreach ($identities as $idx => $ident) {
-            if (strpos($return_path, str_replace('@', '=', $ident['email_ascii']).'@') !== false) {
-                $from_idx = $idx;
-                break;
+            $ident = str_replace('@', '=', $ident['email_ascii']) . '@';
+            foreach ((array)$return_path as $path) {
+                if (strpos($path, $ident) !== false) {
+                    $from_idx = $idx;
+                    break 2;
+                }
             }
         }
     }
