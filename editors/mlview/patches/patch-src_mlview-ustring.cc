$NetBSD: patch-src_mlview-ustring.cc,v 1.1 2011/11/24 14:13:19 joerg Exp $

--- src/mlview-ustring.cc.orig	2011-11-24 02:25:01.000000000 +0000
+++ src/mlview-ustring.cc
@@ -59,7 +59,7 @@ UString::UString (const Glib::ustring &a
 UString::~UString ()
 {}
 
-UString::UString&
+UString&
 UString::operator= (const char *a_cstr)
 {
 	if (!a_cstr)
