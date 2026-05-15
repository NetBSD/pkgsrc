$NetBSD: patch-dfasyn_compdfa.c,v 1.1 2026/05/15 19:04:22 ktnb Exp $

Fix segfault

--- dfasyn/compdfa.c.orig	2017-08-13 21:55:52.000000000 +0000
+++ dfasyn/compdfa.c
@@ -425,7 +425,7 @@ do_next_dfa_state:
 
     for (j=0; j<ntokens; j++) {
       int next_state = dfas[i]->map[j];
-      if (leads_to_result[next_state] == 0) {
+      if (next_state >= 0 && leads_to_result[next_state] == 0) {
         dfas[i]->map[j] = -1;
       }
     }
