$NetBSD: patch-error.c,v 1.1 2023/01/26 01:49:16 gutteridge Exp $

Make sure that error messages are valid UTF-8. Fixes itstool segfaults.
https://gitlab.gnome.org/GNOME/libxml2/-/commit/76c6da420923f2721a2e16adfcef8707a2454a1b

--- error.c.orig	2022-10-14 12:20:48.000000000 +0000
+++ error.c
@@ -163,7 +163,7 @@ xmlParserPrintFileInfo(xmlParserInputPtr
 }
 
 /**
- * xmlParserPrintFileContext:
+ * xmlParserPrintFileContextInternal:
  * @input:  an xmlParserInputPtr input
  *
  * Displays current context within the input content for error tracking
@@ -172,7 +172,7 @@ xmlParserPrintFileInfo(xmlParserInputPtr
 static void
 xmlParserPrintFileContextInternal(xmlParserInputPtr input ,
 		xmlGenericErrorFunc channel, void *data ) {
-    const xmlChar *cur, *base;
+    const xmlChar *cur, *base, *start;
     unsigned int n, col;	/* GCC warns if signed, because compared with sizeof() */
     xmlChar  content[81]; /* space for 80 chars + line terminator */
     xmlChar *ctnt;
@@ -191,19 +191,30 @@ xmlParserPrintFileContextInternal(xmlPar
     while ((n++ < (sizeof(content)-1)) && (cur > base) &&
 	   (*(cur) != '\n') && (*(cur) != '\r'))
         cur--;
-    if ((*(cur) == '\n') || (*(cur) == '\r')) cur++;
+    if ((*(cur) == '\n') || (*(cur) == '\r')) {
+        cur++;
+    } else {
+        /* skip over continuation bytes */
+        while ((cur < input->cur) && ((*cur & 0xC0) == 0x80))
+            cur++;
+    }
     /* calculate the error position in terms of the current position */
     col = input->cur - cur;
     /* search forward for end-of-line (to max buff size) */
     n = 0;
-    ctnt = content;
+    start = cur;
     /* copy selected text to our buffer */
-    while ((*cur != 0) && (*(cur) != '\n') &&
-	   (*(cur) != '\r') && (n < sizeof(content)-1)) {
-		*ctnt++ = *cur++;
-	n++;
+    while ((*cur != 0) && (*(cur) != '\n') && (*(cur) != '\r')) {
+        int len = input->end - cur;
+        int c = xmlGetUTF8Char(cur, &len);
+
+        if ((c < 0) || (n + len > sizeof(content)-1))
+            break;
+        cur += len;
+	n += len;
     }
-    *ctnt = 0;
+    memcpy(content, start, n);
+    content[n] = 0;
     /* print out the selected text */
     channel(data ,"%s\n", content);
     /* create blank line with problem pointer */
