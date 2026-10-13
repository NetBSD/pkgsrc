$NetBSD: patch-src_miscmods_dmarc__common.c,v 1.1 2026/10/13 14:50:26 ryoon Exp $

* Fix a parse error by opendmarc-import.

--- src/miscmods/dmarc_common.c.orig	2026-10-13 14:43:59.739228807 +0000
+++ src/miscmods/dmarc_common.c
@@ -409,7 +409,7 @@ g = string_fmt_append(g, "align_dkim %d\
 	    : ARES_RESULT_UNKNOWN;
 
     g = string_fmt_append(g, "arc %d\n"
-			     "arc_policy %d json[%#Y ]\n",
+			     "arc_policy %d json:[%#Y ]\n",
 			  i,
 			  i == ARES_RESULT_PASS ? DMARC_ARC_POLICY_RESULT_PASS
 			  : i == ARES_RESULT_FAIL ? DMARC_ARC_POLICY_RESULT_FAIL
@@ -420,7 +420,7 @@ g = string_fmt_append(g, "align_dkim %d\
   else
 
 # endif
-    g = string_fmt_append(g, "arc %d\narc_policy %d json[ ]\n",
+    g = string_fmt_append(g, "arc %d\narc_policy %d json:[ ]\n",
 		      ARES_RESULT_UNKNOWN, DMARC_ARC_POLICY_RESULT_UNUSED);
   }
 #endif
