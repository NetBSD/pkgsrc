$NetBSD: patch-core_src_gnatcoll-utils.adb,v 1.1 2025/10/07 20:45:10 dkazankov Exp $

Fix empty output on poll

--- core/src/gnatcoll-utils.adb.orig	2024-09-24 12:28:32.000000000 +0300
+++ core/src/gnatcoll-utils.adb
@@ -638,7 +638,8 @@
          --  This loop runs until the call to Expect raises Process_Died
 
          loop
-            Expect (Command.all, Result, ".+", Timeout => -1);
+            Expect (Command.all, Result, ".+", Timeout => -1,
+               Full_Buffer => True);
 
             declare
                NOutput : String_Access;
