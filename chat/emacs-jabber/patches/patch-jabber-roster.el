$NetBSD: patch-jabber-roster.el,v 1.1 2023/09/09 10:27:20 mef Exp $

wrong number of argument (with emacs28)

--- jabber-roster.el.orig	2013-01-28 09:59:50.000000000 +0900
+++ jabber-roster.el	2023-09-09 19:14:25.122242904 +0900
@@ -816,7 +816,7 @@ three being lists of JID symbols."
 (defalias 'jabber-presence-update-roster 'ignore)
 ;;jabber-presence-update-roster is not needed anymore.
 ;;Its work is done in `jabber-process-presence'."
-(make-obsolete 'jabber-presence-update-roster 'ignore)
+(make-obsolete 'jabber-presence-update-roster 'ignore t)
 
 (defun jabber-next-property (&optional prev)
   "Return position of next property appearence or nil if there is none.
