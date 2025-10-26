$NetBSD: patch-correct.c,v 1.1 2025/10/26 19:16:53 vins Exp $

Fix NULL pointer dereference in lookup() function.

--- correct.c.orig	2022-02-06 07:21:53.852873905 +0000
+++ correct.c
@@ -1536,7 +1536,7 @@ static void save_root_cap (word, pattern
 		return;
 		}
 	    }
-	while (dent->flagfield & MOREVARIANTS)
+	while ((dent->flagfield & MOREVARIANTS) && dent->next != NULL)
 	    {
 	    dent = dent->next;
 	    if (captype (dent->flagfield) == FOLLOWCASE
@@ -1577,7 +1577,7 @@ static void save_root_cap (word, pattern
     len = icharlen (p);
     if (dent->flagfield & MOREVARIANTS)
 	dent = dent->next;	/* Skip place-holder entry */
-    for (  ;  ;  )
+    for (  ; dent != NULL ;  )
 	{
 	if (flagsareok (dent))
 	    {
