$NetBSD: patch-correct.c,v 1.2 2025/11/03 15:56:55 vins Exp $

* Display all bytes from multibyte characters instead of converting them
  into `cat -v' format. This fixes an ugly screen content shown while
  checking UTF-8 files.
* Fix NULL pointer dereference in lookup() function.

--- correct.c.orig	2022-02-06 07:21:53.852873905 +0000
+++ correct.c
@@ -769,11 +769,14 @@ static int show_char (cp, linew, output,
 	ichar = SET_SIZE + laststringch;
     else
 	ichar = chartoichar (ch);
-    if (!vflag  &&  iswordch (ichar)  &&  len == 1)
+    if (!vflag  &&  iswordch (ichar)  &&  len >= 1)
 	{
-	if (output)
-	    (void) putchar (ch);
-	(*cp)++;
+	for (i = 0; i < len; ++i)
+	    {
+		if (output)
+			(void) putchar (**cp);
+		(*cp)++;
+	    }
 	return 1;
 	}
     if (ch == '\t')
@@ -1536,7 +1539,7 @@ static void save_root_cap (word, pattern
 		return;
 		}
 	    }
-	while (dent->flagfield & MOREVARIANTS)
+	while ((dent->flagfield & MOREVARIANTS) && dent->next != NULL)
 	    {
 	    dent = dent->next;
 	    if (captype (dent->flagfield) == FOLLOWCASE
@@ -1577,7 +1580,7 @@ static void save_root_cap (word, pattern
     len = icharlen (p);
     if (dent->flagfield & MOREVARIANTS)
 	dent = dent->next;	/* Skip place-holder entry */
-    for (  ;  ;  )
+    for (  ; dent != NULL ;  )
 	{
 	if (flagsareok (dent))
 	    {
