$NetBSD: patch-bcc_assign.c,v 1.1 2016/12/22 21:02:19 joerg Exp $

--- bcc/assign.c.orig	2016-12-22 12:36:17.114630330 +0000
+++ bcc/assign.c
@@ -56,7 +56,7 @@ struct symstruct *target;
 	    cast(target->type, source);
 	if (tscalar & RSCALAR)
 	{
-	    if (source->storage == CONSTANT && (!reguse & doubleregs))
+	    if (source->storage == CONSTANT && !(reguse & doubleregs))
 		load(source, doubleregs & ~DREG);
 	    if (source->storage != CONSTANT && source->indcount == 0)
 	    {
