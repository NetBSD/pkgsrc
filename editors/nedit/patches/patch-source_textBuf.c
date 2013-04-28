$NetBSD: patch-source_textBuf.c,v 1.1 2013/04/28 20:35:22 dholland Exp $

Silence gcc 4.5 warnings about uninitialized variables.

--- source/textBuf.c~	2004-07-21 11:32:05.000000000 +0000
+++ source/textBuf.c
@@ -1592,6 +1592,9 @@ static void deleteRect(textBuffer *buf, 
 {
     int nLines, lineStart, lineEnd, len, endOffset;
     char *outStr, *outPtr, *line, *text, *expText;
+
+    /* this may be needed if the region is empty */
+    endOffset = 0;
     
     /* allocate a buffer for the replacement string large enough to hold 
        possibly expanded tabs as well as an additional  MAX_EXP_CHAR_LEN * 2
@@ -1998,6 +2001,9 @@ static char *getSelectionText(textBuffer
 {
     int start, end, isRect, rectStart, rectEnd;
     char *text;
+
+    /* silence bogus uninitialized variable warning from gcc 4.5 */
+    rectStart = rectEnd = 0;
     
     /* If there's no selection, return an allocated empty string */
     if (!getSelectionPos(sel, &start, &end, &isRect, &rectStart, &rectEnd)) {
@@ -2018,6 +2024,9 @@ static void removeSelected(textBuffer *b
     int start, end;
     int isRect, rectStart, rectEnd;
     
+    /* silence bogus uninitialized variable warning from gcc 4.5 */
+    rectStart = rectEnd = 0;
+    
     if (!getSelectionPos(sel, &start, &end, &isRect, &rectStart, &rectEnd))
     	return;
     if (isRect)
@@ -2030,6 +2039,9 @@ static void replaceSelected(textBuffer *
 {
     int start, end, isRect, rectStart, rectEnd;
     selection oldSelection = *sel;
+
+    /* silence bogus uninitialized variable warning from gcc 4.5 */
+    rectStart = rectEnd = 0;
     
     /* If there's no selection, return */
     if (!getSelectionPos(sel, &start, &end, &isRect, &rectStart, &rectEnd))
