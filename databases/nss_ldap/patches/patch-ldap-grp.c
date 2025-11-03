$NetBSD: patch-ldap-grp.c,v 1.1 2025/11/03 19:11:50 tron Exp $

Fix build problem system's which provide asprintf(3).

--- ldap-grp.c.orig	2023-07-17 15:52:59.000000000 +0100
+++ ldap-grp.c	2025-11-03 18:09:20.381979654 +0000
@@ -987,7 +987,7 @@
   const char *gidnumber_attrs[3];
   const char **memberP;
   const char **filteredMembersOf; /* remove already traversed groups */
-  const char *filterEntryDN;
+  char *filterEntryDN;
   size_t memberCount, i;
   int erange;
 
