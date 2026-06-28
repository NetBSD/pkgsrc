$NetBSD: patch-Wnn_jserver_jishoop.c,v 1.1 2026/06/28 06:16:27 tsutsui Exp $

- Appease "comparison between pointer and integer" warning

--- Wnn/jserver/jishoop.c.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/jserver/jishoop.c
@@ -531,7 +531,7 @@ found_it:
   if (p->kosuu == 1)
     {
       *next_pter = p->next;
-      if (tary[ind1].pter == NULL)
+      if (tary[ind1].pter == ENDPTR)
         remove_space (tary, ind1, jtl, tary[ind1].pter1);
       if (p->serial == jtl->maxserial - 1)
         {
