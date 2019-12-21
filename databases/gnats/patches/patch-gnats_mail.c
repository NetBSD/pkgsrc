$NetBSD: patch-gnats_mail.c,v 1.1 2019/12/21 23:31:23 joerg Exp $

--- gnats/mail.c.orig	2019-12-21 22:24:31.365425550 +0000
+++ gnats/mail.c
@@ -67,7 +67,7 @@ get_responsible_address (const DatabaseI
   if (res != NULL)
     {
       if (res->admFields[ResponsibleAdmAlias] == NULL ||
-	  res->admFields[ResponsibleAdmAlias] == '\0')
+	  res->admFields[ResponsibleAdmAlias][0] == '\0')
 	{
 	  if (res->admFields[ResponsibleAdmAlias] != NULL)
 	    {
