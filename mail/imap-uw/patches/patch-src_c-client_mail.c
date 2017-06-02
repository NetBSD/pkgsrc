$NetBSD: patch-src_c-client_mail.c,v 1.1 2017/06/02 05:35:21 taca Exp $

Rename hash_lookup() to unusual name to avoid conflict to other
shared libraries.  It should be internal function of libc-client.

--- src/c-client/mail.c.orig	2011-07-23 00:20:18.000000000 +0000
+++ src/c-client/mail.c
@@ -4938,7 +4938,7 @@ THREADNODE *mail_thread_references (MAIL
     if (s->unique && (s->unique != s->message_id))
       fs_give ((void **) &s->unique);
     s->unique = s->message_id ?	/* don't permit Message ID duplicates */
-      (hash_lookup (ht,s->message_id) ? cpystr (tmp) : s->message_id) :
+      (hash_lookup_ (ht,s->message_id) ? cpystr (tmp) : s->message_id) :
 	(s->message_id = cpystr (tmp));
 				/* add unique string to hash table */
     hash_add (ht,s->unique,s,THREADLINKS);
@@ -4960,7 +4960,7 @@ THREADNODE *mail_thread_references (MAIL
       }
     else con = NIL;		/* else message has no ancestors */
 			/* Step 1B */
-    if ((prc = PARENT ((nxc = hash_lookup (ht,s->unique)))) &&
+    if ((prc = PARENT ((nxc = hash_lookup_ (ht,s->unique)))) &&
 	(prc != con)) {		/* break links if have a different parent */
       SETPARENT (nxc,NIL);	/* easy if direct child */
       if (nxc == CHILD (prc)) SETCHILD (prc,SIBLING (nxc));
@@ -5022,7 +5022,7 @@ THREADNODE *mail_thread_references (MAIL
   for (cur = root; cur; cur = cur->branch)
     if ((t = (nxt = (cur->sc ? cur : cur->next))->sc->subject) && *t) {
 				/* add new subject to hash table */
-      if (!(sub = hash_lookup (ht,t))) hash_add (ht,t,cur,0);
+      if (!(sub = hash_lookup_ (ht,t))) hash_add (ht,t,cur,0);
 				/* if one in table not dummy and */
       else if ((s = (lst = (THREADNODE *) sub[0])->sc) &&
 				/* current dummy, or not re/fwd and table is */
@@ -5034,7 +5034,7 @@ THREADNODE *mail_thread_references (MAIL
   for (cur = root, sis = NIL; cur; cur = msg) {
 				/* do nothing if current message or no sub */
     if (!(t = (cur->sc ? cur : cur->next)->sc->subject) || !*t ||
-	((lst = (THREADNODE *) (sub = hash_lookup (ht,t))[0]) == cur))
+	((lst = (THREADNODE *) (sub = hash_lookup_ (ht,t))[0]) == cur))
       msg = (sis = cur)->branch;
     else if (!lst->sc) {	/* is message in the table a dummy? */
 				/* find youngest daughter of msg in table */
