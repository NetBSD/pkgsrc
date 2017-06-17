$NetBSD: patch-pymsgauth.py,v 1.1 2017/06/17 13:55:06 schmonz Exp $

Add pymsgauth-tag, a Unix filter that takes an RFC822 mail message on stdin
and prints it to stdout, adding a pymsgauth token in the header if needed.

--- pymsgauth.py.orig	2003-12-15 16:49:28.000000000 +0000
+++ pymsgauth.py
@@ -362,9 +362,24 @@ def sendmail_wrapper (args):
         mailcmd += args
         log (TRACE, 'mailcmd == %s' % mailcmd)
         buf = cStringIO.StringIO (sys.stdin.read())
-        msg = rfc822.Message (buf, seekable=1)
+        new_buf = tokenize_message_if_needed (buf, args)
+
+        send_mail (new_buf, mailcmd)
+        if (new_buf != buf.getvalue ()):
+            log (TRACE, 'Sent tokenized mail.')
+        else:
+            log (TRACE, 'Passed mail through unchanged.')
+
+    except StandardError, txt:
+        log (FATAL, 'Fatal:  caught exception (%s)' % txt)
+        log_exception ()
+        sys.exit (1)
 
+#############################
+def should_tokenize_message (msg, *args):
+    try:
         sign_message = 0
+
         for arg in args:
             if arg in config['token_recipient']:
                 sign_message = 1
@@ -378,15 +393,27 @@ def sendmail_wrapper (args):
                 if recip in config['token_recipient']:
                     sign_message = 1
                     break
-        if sign_message:
+
+        return sign_message
+
+    except StandardError, txt:
+        log (FATAL, 'Fatal:  caught exception (%s)' % txt)
+        log_exception ()
+        sys.exit (1)
+
+#############################
+def tokenize_message_if_needed (buf, *args):
+    try:
+        read_config ()
+        log (TRACE)
+        msg = rfc822.Message (buf, seekable=1)
+
+        if should_tokenize_message (msg, args):
             token = gen_token (msg)
             log (INFO, 'Generated token %s.' % token)
-            new_buf = '%s: %s\n' % (config['auth_field'], token) + buf.getvalue ()
-            send_mail (new_buf, mailcmd)
-            log (TRACE, 'Sent tokenized mail.')
+            return '%s: %s\n' % (config['auth_field'], token) + buf.getvalue ()
         else:
-            send_mail (buf.getvalue (), mailcmd)
-            log (TRACE, 'Passed mail through unchanged.')
+            return buf.getvalue ()
 
     except StandardError, txt:
         log (FATAL, 'Fatal:  caught exception (%s)' % txt)
