$NetBSD: patch-psg.cpp,v 1.1 2019/09/30 10:05:19 maya Exp $

Avoid narrowing conversion, -1 isn't a valid unsigned number.

--- psg.cpp.orig	2001-03-22 16:02:00.000000000 +0000
+++ psg.cpp
@@ -125,7 +125,7 @@ void PSG::MakeEnvelopTable()
 		2,2, 2,0, 2,1, 2,3, 1,1, 1,3, 1,2, 1,0,
 	};
 	static uint8 table2[4] = {  0,  0, 31, 31 };
-	static uint8 table3[4] = {  0,  1, -1,  0 };
+	static uint8 table3[4] = {  0,  1, 0xFF,  0 };
 
 	if (!enveloptable[0][0])
 	{
