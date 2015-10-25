$NetBSD: patch-lib_canna_keydef.c,v 1.1 2015/10/25 12:17:36 tsutsui Exp $

Pull upstream fix to avoid crash on set-key in ~/.canna (PR pkg/50368).
 https://osdn.jp/cvs/view/canna/canna/lib/canna/keydef.c?view=log#rev1.3

--- lib/canna/keydef.c.orig	2003-09-17 08:50:53.000000000 +0000
+++ lib/canna/keydef.c
@@ -444,12 +444,9 @@ static unsigned int
 createHashKey(data1, data2, which_seq)
 unsigned char *data1;
 unsigned char data2;
-int which_seq;
+unsigned int which_seq;
 {
-  unsigned int hashKey;
-
-  hashKey = (int)(((POINTERINT)data1 + (POINTERINT)data2) % which_seq);
-  return hashKey;
+  return (unsigned int)(((canna_uintptr_t)data1 + (canna_uintptr_t)data2) % which_seq);
 }
 
 /* 機能シーケンスを割り出す */
