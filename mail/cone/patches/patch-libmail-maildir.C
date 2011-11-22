$NetBSD: patch-libmail-maildir.C,v 1.1 2011/11/22 18:12:35 joerg Exp $

Use stdio functions to ensure that the mail::file cast to FILE * happens.

--- libmail/maildir.C.orig	2011-11-22 16:26:47.000000000 +0000
+++ libmail/maildir.C
@@ -31,6 +31,8 @@
 #include <list>
 #include <map>
 
+#undef ferror
+
 using namespace std;
 
 /////////////////////////////////////////////////////////////////////////////
