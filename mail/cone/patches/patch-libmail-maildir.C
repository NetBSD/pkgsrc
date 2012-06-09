$NetBSD: patch-libmail-maildir.C,v 1.2 2012/06/09 11:51:36 adam Exp $

Use stdio functions to ensure that the mail::file cast to FILE * happens.

--- libmail/maildir.C.orig	2011-11-22 16:26:47.000000000 +0000
+++ libmail/maildir.C
@@ -30,6 +30,8 @@
 #include <list>
 #include <map>
 
+#undef ferror
+
 using namespace std;
 
 /////////////////////////////////////////////////////////////////////////////
