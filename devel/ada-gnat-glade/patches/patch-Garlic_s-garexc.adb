$NetBSD: patch-Garlic_s-garexc.adb,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Fix compilation warning
https://github.com/reznikmm/garlic/commit/4d16e8caddbcc83f6d37e14d657a6c8515466cc7

--- Garlic/s-garexc.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Garlic/s-garexc.adb
@@ -113,8 +113,6 @@
    procedure Raise_With_Errno (Id : Exception_Id) is
    begin
       Raise_Exception (Id, "Error" & Integer'Image (Errno));
-      --  Next line will never be called, just to avoid GNAT warnings
-      Raise_With_Errno (Id);
    end Raise_With_Errno;
 
    -----------
