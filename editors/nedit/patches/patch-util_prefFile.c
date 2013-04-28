$NetBSD: patch-util_prefFile.c,v 1.1 2013/04/28 20:35:23 dholland Exp $

Silence gcc warnings about unsafe pointer casts.

--- util/prefFile.c~	2004-07-21 11:32:07.000000000 +0000
+++ util/prefFile.c
@@ -353,9 +353,9 @@ static int stringToPref(const char *stri
       	*(int *)rsrcDescrip->valueAddr = 0;
     	return False;
       case PREF_STRING:
-	if ((int)strlen(string) >= (int)rsrcDescrip->arg)
+	if (strlen(string) >= (uintptr_t)rsrcDescrip->arg)
       	    return False;
-	strncpy(rsrcDescrip->valueAddr, string, (int)rsrcDescrip->arg);
+	strncpy(rsrcDescrip->valueAddr, string, (uintptr_t)rsrcDescrip->arg);
       	return True;
       case PREF_ALLOC_STRING:
       	*(char **)rsrcDescrip->valueAddr = XtMalloc(strlen(string) + 1);
