$NetBSD: patch-richmail_richset.c,v 1.1 2025/10/12 00:57:39 mrg Exp $

Port for GCC 14.


--- richmail/richset.c.orig	1992-10-21 11:04:19.000000000 -0700
+++ richmail/richset.c	2025-10-11 17:44:47.838724358 -0700
@@ -34,6 +34,7 @@
 -------------------------------------------------------------------------*/
 
 #include <stdio.h>
+#include <stdlib.h>
 #include "richlex.h"
 #include "richset.h"
 
@@ -58,6 +59,7 @@ static	int	CharEncStack[MAX_CHAR_SETS];
  * a particular base processor.  The initialisation function of all
  * character set processors is called.
  */
+void
 charsetinit (charset,name)
 struct	charsetproc *charset;
 char	*name;
@@ -76,6 +78,7 @@ char	*name;
  * Initialise the stack, starting with a character set processor with
  * a particular name.
  */
+void
 charsetnameinit	(name)
 char	*name;
 {
@@ -110,6 +113,7 @@ char	*name;
 /*
  * Push a new character set processor onto the stack.
  */
+void
 charsetpush (charset)
 struct	charsetproc *charset;
 {
@@ -128,6 +132,7 @@ struct	charsetproc *charset;
  * if it matches the given processor.  Note: the base
  * processor is never popped off.
  */
+void
 charsetpop (charset)
 struct	charsetproc *charset;
 {
@@ -156,6 +161,7 @@ struct	charsetproc *charset;
  * Set the details for a character set member in the top-most
  * character set.
  */
+void
 charmember (member,ch)
 struct	charsetmember *member;
 RCHAR	ch;
@@ -167,6 +173,7 @@ RCHAR	ch;
 /*
  * Set the details for a member of a specific character set.
  */
+void
 charmemberspec (member,ch,charset)
 struct	charsetmember *member;
 RCHAR	ch;
@@ -179,6 +186,7 @@ struct	charsetproc *charset;
 /*
  * Set the details for a output control code character.
  */
+void
 charmemberctrl (member,ch)
 struct	charsetmember *member;
 RCHAR	ch;
