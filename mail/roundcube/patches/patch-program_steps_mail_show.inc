$NetBSD: patch-program_steps_mail_show.inc,v 1.1 2013/06/15 16:08:09 taca Exp $

Fix from repository:
* commit acb4b71ce55f3d98f7053b7bb8fdcf3c7858fbfc:
  Fix error when there's no writeable addressbook source (#1489162) 

--- program/steps/mail/show.inc.orig	2013-05-16 18:06:36.000000000 +0000
+++ program/steps/mail/show.inc
@@ -255,9 +255,13 @@ function rcmail_contact_exists($email)
   if ($email) {
     // @TODO: search in all address books?
     $CONTACTS = $RCMAIL->get_address_book(-1, true);
-    $existing = $CONTACTS->search('email', $email, true, false);
-    if ($existing->count)
-      return true;
+
+    if (is_object($CONTACTS)) {
+      $existing = $CONTACTS->search('email', $email, true, false);
+      if ($existing->count) {
+        return true;
+      }
+    }
   }
 
   return false;
