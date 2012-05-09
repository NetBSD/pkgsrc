$NetBSD: patch-src_xgselect.c,v 1.1 2012/05/09 09:30:07 wiz Exp $

http://debbugs.gnu.org/cgi/bugreport.cgi?bug=10631

--- src/xgselect.c.orig	2012-01-11 12:35:01.000000000 +0000
+++ src/xgselect.c
@@ -55,6 +55,9 @@ xg_select (max_fds, rfds, wfds, efds, ti
   do {
     if (n_gfds > gfds_size) 
       {
+        if (gfds_size == 0)
+          xgselect_initialize ();
+
         while (n_gfds > gfds_size) 
           gfds_size *= 2;
         xfree (gfds);
