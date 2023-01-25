$NetBSD: patch-libs_maildrop_main.C,v 1.3 2023/01/25 19:34:04 bsiegert Exp $

Make this maildrop install usable by both Courier and other MTAs.

--- libs/maildrop/main.C.orig	2021-05-22 09:00:07.000000000 +0000
+++ libs/maildrop/main.C
@@ -279,11 +279,13 @@ static int callback_authlib(struct authi
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
@@ -758,7 +760,7 @@ uid_t	my_u=getuid();
 	if (!found)
 	{
 #if HAVE_COURIER
-		if (!deliverymode)
+		if (!deliverymode || !getenv("COURIER_MTA"))
 #endif
 		{
 			my_pw=getpwuid(my_u);
@@ -818,6 +820,14 @@ Buffer	value;
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
 
@@ -842,6 +852,8 @@ Buffer	value;
 
 		if ((p=getenv("MAILDIRQUOTA")) && *p)
 			maildrop.init_quota=p;
+
+		}	/* COURIER_MTA */
 	}
 #endif
 
