$NetBSD: patch-ncurses_tinfo_alloc__entry.c,v 1.1 2017/08/08 18:38:21 spz Exp $

from ftp://invisible-island.net/ncurses/6.0/ncurses-6.0-20170701.patch.gz
+ add/improve checks in tic's parser to address invalid input
 (Redhat #1464684, #1464685, #1464686, #1464691).
 + alloc_entry.c, add a check for a null-pointer.
 + parse_entry.c, add several checks for valid pointers as well as
   one check to ensure that a single character on a line is not
   treated as the 2-character termcap short-name.

that's CVE-2017-10684 CVE-2017-10685 CVE-2017-11112 CVE-2017-11113


--- ncurses/tinfo/alloc_entry.c.orig	2013-08-17 19:20:38.000000000 +0000
+++ ncurses/tinfo/alloc_entry.c
@@ -96,7 +96,11 @@ _nc_save_str(const char *const string)
 {
     char *result = 0;
     size_t old_next_free = next_free;
-    size_t len = strlen(string) + 1;
+    size_t len;
+
+    if (string == 0)
+	return _nc_save_str("");
+    len = strlen(string) + 1;
 
     if (len == 1 && next_free != 0) {
 	/*
