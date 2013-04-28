$NetBSD: patch-source_textDisp.c,v 1.1 2013/04/28 20:35:22 dholland Exp $

Silence gcc 4.5 warnings about uninitialized variables.

--- source/textDisp.c~	2004-07-21 11:32:05.000000000 +0000
+++ source/textDisp.c
@@ -1502,6 +1502,9 @@ static void bufModifiedCB(int pos, int n
     int oldFirstChar = textD->firstChar;
     int scrolled, origCursorPos = textD->cursorPos;
     int wrapModStart, wrapModEnd;
+
+    /* silence bogus uninitialized variable warning from gcc 4.5 */
+    wrapModStart = wrapModEnd = -1;
  
     /* buffer modification cancels vertical cursor motion column */
     if (nInserted != 0 || nDeleted != 0)
