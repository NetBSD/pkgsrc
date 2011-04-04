$NetBSD: patch-src_lib_util_astring.h,v 1.5 2011/04/04 12:09:03 wiz Exp $

toupper is a macro on NetBSD.
Sent upstream.

--- src/lib/util/astring.h.orig	2011-02-01 20:29:56.000000000 +0000
+++ src/lib/util/astring.h
@@ -396,7 +396,7 @@ public:
 
 	astring &delchr(int ch) { return *astring_delchr(this, ch); }
 	astring &replacechr(int ch, int newch) { return *astring_replacechr(this, ch, newch); }
-	astring &toupper() { return *astring_toupper(this); }
+	astring &upper() { return *astring_toupper(this); }
 	astring &tolower() { return *astring_tolower(this); }
 	astring &trimspace() { return *astring_trimspace(this); }
 };
