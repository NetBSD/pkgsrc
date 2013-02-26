$NetBSD: patch-src_a__sort.c,v 1.1 2013/02/26 11:08:17 joerg Exp $

--- src/a_sort.c.orig	2013-02-25 16:39:10.000000000 +0000
+++ src/a_sort.c
@@ -34,6 +34,8 @@ static char rcsid[] = "@(#)$Id: a_sort.c
 #include "elm_globals.h"
 #include "s_aliases.h"
 
+static void alias_old_current(long iindex);
+
 char *alias_sort_name();
 
 sort_aliases(entries, visible, are_in_aliases)
@@ -179,8 +181,7 @@ int longname;
     return("*UNKNOWN-SORT-PARAMETER*");
 }
 
-alias_old_current(iindex)
-long iindex;
+static void alias_old_current(long iindex)
 {
 	/** Set current to the message that has "index" as it's 
 	    index number.  This is to track the current message
