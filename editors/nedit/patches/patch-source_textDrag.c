$NetBSD: patch-source_textDrag.c,v 1.1 2013/04/28 20:35:22 dholland Exp $

Silence gcc 4.5 warnings about uninitialized variables.

--- source/textDrag.c~	2004-07-21 11:32:05.000000000 +0000
+++ source/textDrag.c
@@ -188,6 +188,10 @@ void BlockDragSelection(TextWidget tw, i
     if (tw->text.dragState != PRIMARY_BLOCK_DRAG)
     	return;
 
+    /* gcc 4.5 warns that these are uninitialized, not clear if it's right */
+    tempModRangeEnd = -1;
+    bufModRangeEnd = -1;
+
     /* The operation of block dragging is simple in theory, but not so simple
        in practice.  There is a backup buffer (tw->text.dragOrigBuf) which
        holds a copy of the buffer as it existed before the drag.  When the
