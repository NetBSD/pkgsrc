$NetBSD: patch-msgs.c,v 1.2 2015/12/29 04:04:28 dholland Exp $

Avoid pointer<->integer conversions

--- msgs.c	2013-11-04 10:20:09.000000000 -0500
+++ msgs.c	2013-11-04 10:28:09.000000000 -0500
@@ -817,7 +817,7 @@
 	cnt = msg_cnt;
 	(void) fseek(fp, append == 1 ? msg[cnt].m_offset : 0L, L_SET);
     } else {
-	cnt = (int)list;
+	cnt = *(int *)list;
 	old = msg[cnt];
     }
 
Only in www: mush.core
