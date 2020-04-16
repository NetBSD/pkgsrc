$NetBSD: patch-libs_maildrop_main.C,v 1.2 2020/04/16 12:49:35 manu Exp $

Make this maildrop install usable by both Courier and other MTAs.

--- libs/maildrop/main.C.orig	2018-09-14 01:22:17.000000000 +0200
+++ libs/maildrop/main.C	2020-04-10 03:32:11.795122838 +0200
@@ -278,13 +278,15 @@
 			    void *void_arg)
 {
 	Maildrop &maildrop=*(Maildrop *)void_arg;
 
+#if 0 /* auth_mkhomedir does not exist in courrier-authlib */
 	if (auth_mkhomedir(auth))
 	{
 		perror(auth->homedir);
 		exit(1);
 	}
+#endif
 
 	if (VerboseLevel() > 1)
 	{
 		Buffer b;
@@ -753,9 +755,9 @@
 
 	if (!found)
 	{
 #if HAVE_COURIER
-		if (!deliverymode)
+		if (!deliverymode || !getenv("COURIER_MTA"))
 #endif
 		{
 			my_pw=getpwuid(my_u);
 			if (!my_pw)
@@ -813,8 +815,16 @@
 	if (deliverymode && orig_uid == getuid())
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
 
 		if ((p=getenv("LOGNAME")) && *p)
@@ -837,8 +847,10 @@
 		maildrop.init_default=p;
 
 		if ((p=getenv("MAILDIRQUOTA")) && *p)
 			maildrop.init_quota=p;
+
+		}	/* COURIER_MTA */
 	}
 #endif
 
 	if (deliverymode)
