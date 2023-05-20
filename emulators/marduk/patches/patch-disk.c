$NetBSD: patch-disk.c,v 1.1 2023/05/20 12:47:47 thorpej Exp $

Add missing return values from disksys_init() and disksys_deinit().

--- disk.c.orig	2023-05-19 20:40:28
+++ disk.c	2023-05-19 20:40:43
@@ -305,6 +305,7 @@ int disksys_init (void)
  diag_printf ("Initializing disk system\n");
  disksys_light=0;
  mode=tick=subtick=0;
+ return 0;
 }
 
 int disksys_deinit (void)
@@ -314,5 +315,6 @@ int disksys_deinit (void)
  disktype[0]=disktype[1]=DISK_NONE;
  diag_printf ("Shutting down disk system\n");
  disksys_light=0;
+ return 0;
 }
 
