$NetBSD: patch-Dist_xe__names.ads,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Fix some compilation warnings
https://github.com/reznikmm/garlic/commit/b738f20db65add57f817f952a625df73bef0710e

--- Dist/xe_names.ads.orig	2007-11-26 14:06:30.000000000 +0200
+++ Dist/xe_names.ads
@@ -48,7 +48,7 @@
 --  names table entry and subprograms are provided for setting and retrieving
 --  these associated values. The usage of these values is up to the client.
 
-   Name_Buffer : String (1 .. 16*1024);
+   Name_Buffer : String (1 .. 16 * 1024);
    --  This buffer is used to set the name to be stored in the table for the
    --  Name_Find call, and to retrieve the name for the Get_Name_String call.
    --  The plus 1 in the length allows for cases of adding ASCII.NUL. The
