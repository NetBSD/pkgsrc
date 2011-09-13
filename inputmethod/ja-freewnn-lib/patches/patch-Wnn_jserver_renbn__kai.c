$NetBSD: patch-Wnn_jserver_renbn__kai.c,v 1.1 2011/09/13 07:23:17 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/jserver/renbn_kai.c.orig	2002-09-01 17:13:11.000000000 +0000
+++ Wnn/jserver/renbn_kai.c
@@ -6,9 +6,9 @@
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
  * Copyright ASTEC, Inc. 1987, 1988, 1989, 1990, 1991, 1992
- * Copyright FreeWnn Project 1999, 2000, 2002
+ * Copyright FreeWnn Project 1999, 2000, 2002, 2011
  *
- * Maintainer:  FreeWnn Project   <freewnn@tomo.gr.jp>
+ * Maintainer:  FreeWnn Project
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
@@ -321,7 +321,7 @@ tan_syo (int yomi_sno,		/* ≤Ú¿œ ∏ª˙ŒÛ st
   _status = 0;
   if (chk_yomi_endvect (yomi_sno, yomi_eno, endvect, endvect1) < 0)
     return (-1);
-  if (sbn_kai (yomi_sno, yomi_eno, endvect, endvect1, &rsbnptr, 1, 0) < 0)
+  if (sbn_kai (yomi_sno, yomi_eno, endvect, endvect1, &rsbnptr, 1, (struct SYO_BNSETSU *) 0) < 0)
     {
       init_work_areas ();
       return (-1);              /* ERROR */
