$NetBSD: patch-pcre_compile.c,v 1.1 2016/03/18 21:25:10 tez Exp $

Fix for CVE-2016-1283 from
 http://vcs.pcre.org/pcre?view=revision&revision=1636

--- pcre_compile.c.orig	2016-03-18 21:00:47.095736300 +0000
+++ pcre_compile.c
@@ -7274,7 +7274,12 @@ for (;; ptr++)
           so far in order to get the number. If the name is not found, leave
           the value of recno as 0 for a forward reference. */
 
-          else
+	  /* This patch (removing "else") fixes a problem when a reference is
+	  to multiple identically named nested groups from within the nest.
+	  Once again, it is not the "proper" fix, and it results in an
+	  over-allocation of memory. */
+
+          /* else */
             {
             ng = cd->named_groups;
             for (i = 0; i < cd->names_found; i++, ng++)
