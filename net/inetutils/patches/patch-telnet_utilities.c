$NetBSD: patch-telnet_utilities.c,v 1.1 2018/12/13 05:34:38 maya Exp $

Avoid infinite loop. This is an error exit.

--- telnet/utilities.c.orig	2015-03-31 15:40:50.000000000 +0000
+++ telnet/utilities.c
@@ -1062,7 +1062,6 @@ Exit (int returnCode)
 void
 ExitString (char *string, int returnCode)
 {
-  SetForExit ();
   fwrite (string, 1, strlen (string), stderr);
   exit (returnCode);
 }
