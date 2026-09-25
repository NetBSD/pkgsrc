$NetBSD: patch-src_tail.c,v 1.2 2026/09/25 07:14:32 wiz Exp $

https://debbugs.gnu.org/cgi/bugreport.cgi?bug=81923

--- src/tail.c.orig	2026-07-31 13:51:12.000000000 +0000
+++ src/tail.c
@@ -1177,6 +1177,10 @@ tail_forever (struct File_spec *f, int n_files, double
 
   static bool debugged;
 
+  /* Flush initial output as we might block reading a FIFO.  */
+  if (fflush (stdout) < 0)
+    write_error ();
+
   while (true)
     {
       /* Use blocking I/O as an optimization, when it's easy.  */
