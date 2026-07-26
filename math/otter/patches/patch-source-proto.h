$NetBSD: patch-source-proto.h,v 1.1 2026/07/26 06:14:13 rillig Exp $

Fix typo.

--- source/proto.h.orig	1999-12-01 22:39:40.000000000 +0000
+++ source/proto.h
@@ -542,7 +542,7 @@ void dp_transform();
 void dp_p_term();
 int clause_to_pair();
 void dp_transform();
-void igcns_transform();
+void icgns_transform();
 
 /* check.c */
 
