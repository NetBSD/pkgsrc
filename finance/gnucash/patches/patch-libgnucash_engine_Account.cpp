$NetBSD: patch-libgnucash_engine_Account.cpp,v 1.1 2024/07/05 08:08:01 wiz Exp $

commit 60ccca017f1be3af2caebb8a9d0c82a197f1da4f
Author: John Ralls <jralls@ceridwen.us>
Date:   Mon Jul 1 21:28:43 2024 -0700

    Bug 799347 - Edit account to make it sub account under other account

    Send QOF_EVENT_REMOVE on the child before actually removing it from
    the children vector so that the stored indexes are valid long enough
    to clear them.

--- libgnucash/engine/Account.cpp.orig	2024-06-27 20:21:49.000000000 +0000
+++ libgnucash/engine/Account.cpp
@@ -2859,11 +2859,13 @@ gnc_account_remove_child (Account *paren
     ed.node = parent;
     ed.idx = gnc_account_child_index (parent, child);
 
+    // First send the event before we invalidate everything in children.
+    qof_event_gen(&child->inst, QOF_EVENT_REMOVE, &ed);
+
+    // Then remove the child and release its memory.
     ppriv->children.erase (std::remove (ppriv->children.begin(), ppriv->children.end(), child),
                            ppriv->children.end());
 
-    /* Now send the event. */
-    qof_event_gen(&child->inst, QOF_EVENT_REMOVE, &ed);
 
     /* clear the account's parent pointer after REMOVE event generation. */
     cpriv->parent = nullptr;
