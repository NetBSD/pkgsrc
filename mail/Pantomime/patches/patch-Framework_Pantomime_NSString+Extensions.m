$NetBSD: patch-Framework_Pantomime_NSString+Extensions.m,v 1.1 2011/11/25 22:00:32 joerg Exp $

--- Framework/Pantomime/NSString+Extensions.m.orig	2011-11-25 13:35:45.000000000 +0000
+++ Framework/Pantomime/NSString+Extensions.m
@@ -42,8 +42,6 @@
 #ifdef MACOSX
 #include <CoreFoundation/CFString.h>
 #include <CoreFoundation/CFStringEncodingExt.h>
-#else
-#include <GNUstepBase/GSCategories.h>
 #endif
 
 #include <ctype.h>
