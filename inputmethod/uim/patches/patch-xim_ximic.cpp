$NetBSD: patch-xim_ximic.cpp,v 1.1 2024/04/07 04:24:23 pho Exp $

Don't use alloca(3). It's non-standard and is easily avoidable these days.
TODO: Upstream this.

--- xim/ximic.cpp.orig	2024-04-07 04:12:30.183013562 +0000
+++ xim/ximic.cpp
@@ -49,10 +49,6 @@
 #include "util.h"
 
 #include "uim/uim-scm.h"
- 
-#ifdef HAVE_ALLOCA_H
-# include <alloca.h>
-#endif
 
 char invalid_style_msg[]=
 "Client requested unsupported input style";
@@ -214,7 +210,7 @@ void icxatr::set_atr(C16 id, C8 *val, in
     case ICA_FontSet:
     {
 	int len = readC16(val, o);
-	char *new_fsn = (char *)alloca(len + 1);
+	char new_fsn[len + 1];
 	new_fsn[len] = '\0';
 	memcpy(new_fsn, &val[2], len);
 	if (font_set_name && !strcmp(font_set_name, new_fsn))
@@ -497,8 +493,7 @@ void XimIC::setICAttrs(void *val, int le
 	atr_len = readC16(&p[i], byte_order);
 	i += 2;
 
-	unsigned char *q;
-	q = (unsigned char *)alloca(atr_len + pad4(atr_len));
+	unsigned char q[atr_len + pad4(atr_len)];
 
 	int j;
 	for (j = 0; j < atr_len + pad4(atr_len); j++, i++) {
@@ -691,8 +686,7 @@ XimIC *create_ic(Connection *c, RxPacket
     p->rewind();
     p->getC16(); // discard
     int atr_len = p->getC16();
-    unsigned char *v;
-    v = (unsigned char *)alloca(atr_len);
+    unsigned char v[atr_len];
     int i;
     for (i = 0; i < atr_len; i++) {
 	v[i] = p->getC8();
