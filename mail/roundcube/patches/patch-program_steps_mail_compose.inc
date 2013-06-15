$NetBSD: patch-program_steps_mail_compose.inc,v 1.1 2013/06/15 16:08:09 taca Exp $

Fix from repository:
* commit 0a7df4a32e86a103a5f1fe801374383a195ba1a5:
  Fix so bounces addresses in Sender headers are skipped on Reply-All
  (#1489011)
* commit aafc0a3d24149da9f7350f760932898319041815:
   Fix so non-inline images aren't skipped on forward (#1489150)

--- program/steps/mail/compose.inc.orig	2013-05-16 18:06:36.000000000 +0000
+++ program/steps/mail/compose.inc
@@ -143,7 +143,7 @@ $OUTPUT->set_env('top_posting', intval($
 $OUTPUT->set_env('recipients_separator', trim($RCMAIL->config->get('recipients_separator', ',')));
 
 // default font for HTML editor
-$font = rcube_fontdefs($RCMAIL->config->get('default_font', 'Verdana'));
+$font = rcube_fontdefs($RCMAIL->config->get('default_font'));
 if ($font && !is_array($font)) {
   $OUTPUT->set_env('default_font', $font);
 }
@@ -318,7 +318,8 @@ foreach ($parts as $header) {
         $fvalue .= $v;
       if ($v = $MESSAGE->headers->cc)
         $fvalue .= (!empty($fvalue) ? $separator : '') . $v;
-      if ($v = $MESSAGE->headers->get('Sender', false))
+      // Use Sender header (#1489011)
+      if (($v = $MESSAGE->headers->get('Sender', false)) && strpos($v, '-bounces@') === false)
         $fvalue .= (!empty($fvalue) ? $separator : '') . $v;
 
       // When To: and Reply-To: are the same we add From: address to the list (#1489037)
@@ -1007,8 +1008,8 @@ function rcmail_write_compose_attachment
       if ($part->ctype_primary == 'message' && $compose_mode == RCUBE_COMPOSE_REPLY) {
         continue;
       }
-      // skip inline images when forwarding in plain text
-      if ($part->content_id && !$bodyIsHtml && $compose_mode == RCUBE_COMPOSE_FORWARD) {
+      // skip inline images when forwarding
+      if ($part->content_id && $part->disposition == 'inline' && $compose_mode == RCUBE_COMPOSE_FORWARD) {
         continue;
       }
 
