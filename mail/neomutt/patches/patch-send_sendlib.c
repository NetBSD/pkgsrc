$NetBSD: patch-send_sendlib.c,v 1.1 2022/01/13 16:12:52 wiz Exp $

Back out the patch for
https://github.com/neomutt/neomutt/issues/3086
since it causes segfaults, see
https://github.com/neomutt/neomutt/issues/3129

--- send/sendlib.c.orig	2021-10-29 12:49:16.000000000 +0000
+++ send/sendlib.c
@@ -1547,6 +1547,7 @@ int mutt_write_fcc(const char *path, str
   if (!mx_mbox_open(m_fcc, MUTT_APPEND | MUTT_QUIET))
   {
     mutt_debug(LL_DEBUG1, "unable to open mailbox %s in append-mode, aborting\n", path);
+    mailbox_free(&m_fcc);
     goto done;
   }
 
@@ -1745,10 +1746,8 @@ int mutt_write_fcc(const char *path, str
     set_noconv_flags(e->body, false);
 
 done:
-  m_fcc->append = old_append;
-  if (m_fcc->flags == MB_HIDDEN)
-    mailbox_free(&m_fcc);
-
+  if (m_fcc)
+    m_fcc->append = old_append;
 #ifdef RECORD_FOLDER_HOOK
   /* We ran a folder hook for the destination mailbox,
    * now we run it for the user's current mailbox */
