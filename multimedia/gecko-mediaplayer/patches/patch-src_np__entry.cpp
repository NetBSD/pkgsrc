$NetBSD: patch-src_np__entry.cpp,v 1.1 2011/12/29 16:34:03 joerg Exp $

--- src/np_entry.cpp.orig	2011-12-29 14:02:59.000000000 +0000
+++ src/np_entry.cpp
@@ -80,9 +80,9 @@ NPError OSCALL NP_GetEntryPoints(NPPlugi
 
 #endif                          /* XP_WIN */
 
-char *NPP_GetMIMEDescription();
+const char *NPP_GetMIMEDescription();
 
-char *NP_GetMIMEDescription()
+const char *NP_GetMIMEDescription()
 {
     return NPP_GetMIMEDescription();
 }
