$NetBSD: patch-speech__tools_utils_EST__ServiceTable.cc,v 1.1 2012/05/04 16:01:04 joerg Exp $

--- speech_tools/utils/EST_ServiceTable.cc.orig	2012-04-27 12:30:06.000000000 +0000
+++ speech_tools/utils/EST_ServiceTable.cc
@@ -68,6 +68,7 @@ int gethostname(char *name, int namelen)
 }
 #endif
 
+Declare_KVL_T(EST_String, EST_ServiceTable::Entry, EST_String_ST_entry)
 
 EST_ServiceTable::EntryTable EST_ServiceTable::entries;
 bool EST_ServiceTable::random_init=FALSE;
@@ -339,7 +340,6 @@ const EST_ServiceTable::Entry &EST_Servi
 
 
 
-Declare_KVL_T(EST_String, EST_ServiceTable::Entry, EST_String_ST_entry)
 
 #if defined(INSTANTIATE_TEMPLATES)
 
