$NetBSD: patch-libs_maildrop_main.C,v 1.1 2019/05/24 13:17:58 hauke Exp $

Make this maildrop install usable by both Courier and other MTAs.

--- libs/maildrop/main.C.orig	2018-09-13 23:22:17.000000000 +0000
+++ libs/maildrop/main.C
@@ -754,7 +754,7 @@ uid_t	my_u=getuid();
 	if (!found)
 	{
 #if HAVE_COURIER
-		if (!deliverymode)
+		if (!deliverymode || !getenv("COURIER_MTA"))
 #endif
 		{
 			my_pw=getpwuid(my_u);
@@ -814,6 +814,14 @@ Buffer	value;
 	{
 	const char *p;
 
+		/*
+		 * To allow one maildrop to be used by both courier MTA
+		 * and others, we require courier MTA to set COURIER_MTA
+		 * in the environment before running maildrop.
+		 */
+		if (getenv("COURIER_MTA"))
+		{	/* COURIER_MTA */
+
 		if ((p=getenv("HOME")) && *p)
 			maildrop.init_home=p;
 
@@ -838,6 +846,8 @@ Buffer	value;
 
 		if ((p=getenv("MAILDIRQUOTA")) && *p)
 			maildrop.init_quota=p;
+
+		}	/* COURIER_MTA */
 	}
 #endif
 
