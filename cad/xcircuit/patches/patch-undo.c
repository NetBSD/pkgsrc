$NetBSD: patch-undo.c,v 1.1 2013/03/02 18:21:39 joerg Exp $

--- undo.c.orig	2013-03-01 15:02:52.000000000 +0000
+++ undo.c
@@ -532,7 +532,7 @@ short undo_one_action()
    thisrecord = xobjs.undostack;
    if (thisrecord == NULL) {
       Fprintf(stderr, "Nothing to undo!\n");
-      return;
+      return -1;
    }
 
    xobjs.undostack = thisrecord->next;
@@ -775,7 +775,7 @@ short redo_one_action()
    thisrecord = xobjs.redostack;
    if (thisrecord == NULL) {
       Fprintf(stderr, "Nothing to redo!\n");
-      return;
+      return -1;
    }
    xobjs.undostack = thisrecord;
    xobjs.redostack = thisrecord->last;
