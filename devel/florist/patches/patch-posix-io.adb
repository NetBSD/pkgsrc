$NetBSD: patch-posix-io.adb,v 1.3 2004/06/30 11:23:43 shannonjr Exp $

--- posix-io.adb.orig	2002-10-24 02:03:52.000000000 -0600
+++ posix-io.adb
@@ -631,6 +631,7 @@ package body POSIX.IO is
       To   : in Boolean := True) is
       Flags : Bits;
       Result : int;
+      pragma Warnings (Off, Result);
    begin
       Begin_Critical_Section;
       Flags := To_Bits (fcntl (int (File), F_GETFD));
