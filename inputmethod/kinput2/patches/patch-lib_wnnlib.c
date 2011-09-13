$NetBSD: patch-lib_wnnlib.c,v 1.1 2011/09/13 07:28:48 mef Exp $

To compile with ja-freewnn-lib-1.11alpah22

--- lib/wnnlib.c.orig	2002-10-03 18:35:28.000000000 +0900
+++ lib/wnnlib.c	2011-05-08 23:37:11.000000000 +0900
@@ -282,7 +282,7 @@
  *
  * struct wnn_buf jcOpen(char *servername, char *envname,
  *			 char *rcfilename, int override,
- *			 void (*errmsgfunc)(), int (*confirmfunc)(),
+ *			 int (*errmsgfunc)(const char *), int (*confirmfunc)(const char *),
  *			 int timeout)
  *	jl_open あるいは jl_open_lang に対応した wnnlib のインタフェー
  *	スで、この関数の中で実際に jl_open あるいは jl_open_lang を呼
@@ -581,6 +581,7 @@
 #include	"wnnlib.h"
 #include	"WStr.h"
 #include	<string.h>
+#include	<stdlib.h>
 #include	<pwd.h>
 #include	<X11/Xos.h>
 
@@ -1367,7 +1368,7 @@
 
 	/* 変換文字列の長さのチェック */
 	clp = buf->clauseInfo + cl;
-	len = jl_kanji_len(buf->wnn, cl);
+	len = jl_kanji_len(buf->wnn, cl, -1);
 	diff = len - ((clp + 1)->dispp - clp->dispp);
 	newlen = (buf->displayEnd - buf->displayBuf) + diff;
 	if (newlen > buf->bufferSize) {
@@ -3449,8 +3450,8 @@
 char *envname;
 int override;
 char *rcfile;
-void (*errmsg)();
-int (*confirm)();
+int (*errmsg)(const char *);
+int (*confirm)(const char *);
 int timeout;
 {
     return jcOpen2(server, envname, override, rcfile, rcfile, errmsg, confirm, timeout);
@@ -3463,8 +3464,8 @@
 int override;
 char *rcfile4;		/* wnnenvrc for Wnn4 */
 char *rcfile6;		/* wnnenvrc for Wnn6 */
-void (*errmsg)();
-int (*confirm)();
+int (*errmsg)(const char *);
+int (*confirm)(const char *);
 int timeout;
 {
     struct wnn_buf *wnnbuf;
