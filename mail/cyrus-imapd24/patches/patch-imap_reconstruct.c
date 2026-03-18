$NetBSD: patch-imap_reconstruct.c,v 1.1 2026/03/18 17:06:32 nia Exp $

Fix implicit function declaration.

--- imap/reconstruct.c.orig	2026-03-18 16:32:20.408867902 +0000
+++ imap/reconstruct.c
@@ -126,6 +126,7 @@ const int config_need_data = CONFIG_NEED
 /* forward declarations */
 void do_mboxlist(void);
 int do_reconstruct(char *name, int matchlen, int maycreate, void *rock);
+void mailbox_make_uniqueid(struct mailbox *mailbox);
 int reconstruct(char *name, struct discovered *l);
 void usage(void);
 char * getmailname (char * mailboxname);
