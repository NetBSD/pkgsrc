$NetBSD: patch-class_deliver_Deliver__SendMail.class.php,v 1.1.2.2 2017/04/20 18:27:26 bsiegert Exp $

Patch CVE-2017-7692 by separately escaping $envelopefrom
concatenating it with a space before escaping allows for injecting command
parameters.

From Filippo Cavallarin
https://www.wearesegment.com/research/Squirrelmail-Remote-Code-Execution.html

--- class/deliver/Deliver_SendMail.class.php.orig	2016-01-01 20:04:30.000000000 +0000
+++ class/deliver/Deliver_SendMail.class.php
@@ -95,9 +95,9 @@ class Deliver_SendMail extends Deliver {
         $envelopefrom = trim($from->mailbox.'@'.$from->host);
         $envelopefrom = str_replace(array("\0","\n"),array('',''),$envelopefrom);
         // save executed command for future reference
-        $this->sendmail_command = "$sendmail_path $this->sendmail_args -f$envelopefrom";
+        $this->sendmail_command = escapeshellcmd("$sendmail_path $this->sendmail_args -f") . escapeshellarg($envelopefrom);
         // open process handle for writing
-        $stream = popen(escapeshellcmd($this->sendmail_command), "w");
+        $stream = popen($this->sendmail_command, "w");
         return $stream;
     }
 
