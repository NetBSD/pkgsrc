$NetBSD: patch-sope-mime_NGMime_NGMimeType.m,v 1.1 2023/01/14 01:44:43 manu Exp $

Fix encoding names that changed in recent gnustep-base 

--- sope-mime/NGMime/NGMimeType.m.orig	2023-01-12 16:39:17.664895627 +0100
+++ sope-mime/NGMime/NGMimeType.m	2023-01-12 16:44:48.022243406 +0100
@@ -120,15 +120,15 @@
   else if ([charset isEqualToString:@"euc-kr"]) {
     encoding = NSKoreanEUCStringEncoding;
   }
   else if ([charset isEqualToString:@"big5"]) {
-    encoding = NSBIG5StringEncoding;
+    encoding = NSBig5StringEncoding;
   }
   else if ([charset isEqualToString:@"iso-2022-jp"]) {
     encoding = NSISO2022JPStringEncoding;
   }
   else if ([charset isEqualToString:@"gb2312"]) {
-    encoding = NSGB2312StringEncoding;
+    encoding = NSGB_2312_80StringEncoding;
   }
   else if ([charset isEqualToString:@"koi8-r"]) {
     encoding = NSKOI8RStringEncoding;
   }
