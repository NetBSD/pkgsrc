$NetBSD: patch-Wnn_jlib.V3_jlv3.c,v 1.1 2026/07/10 23:32:37 tsutsui Exp $

- Remove unnecessary old style declaration for standard C function

--- Wnn/jlib.V3/jlv3.c.orig	2015-05-10 01:39:28.000000000 +0000
+++ Wnn/jlib.V3/jlv3.c
@@ -125,7 +125,6 @@ static struct wnn_ret_buf ret_buf = { 0,
 static char *
 getlogname ()
 {
-  extern struct passwd *getpwuid ();
   struct passwd *p;
 
   if ((p = getpwuid (getuid ())) == NULL)
