$NetBSD: patch-src_lookup_lookup.h,v 1.1 2013/03/20 05:25:58 obache Exp $

* fixes bogus NULL usage, as Integer 0.

--- src/lookup/lookup.h.orig	2008-07-30 12:38:00.000000000 +0000
+++ src/lookup/lookup.h
@@ -42,7 +42,7 @@ struct lookup_value_t{
     gfloat m_poss;
     gint32 m_last_step;
     lookup_value_t(gfloat poss = FLT_MAX){
-	m_handles[0] = NULL; m_handles[1] = NULL;
+	m_handles[0] = 0; m_handles[1] = 0;
 	m_poss = poss;
 	m_last_step = -1;
     }
