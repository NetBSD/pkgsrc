$NetBSD: patch-richmail_richset.h,v 1.1 2025/10/12 00:57:39 mrg Exp $

Port for GCC 14.


--- richmail/richset.h.orig	1992-10-21 11:04:19.000000000 -0700
+++ richmail/richset.h	2025-10-11 17:29:42.796053973 -0700
@@ -89,25 +89,25 @@ struct	charsetmember
  * a particular base processor.  The initialisation function of all
  * character set processors is called.
  */
-extern	charsetinit	( /* struct charsetproc *charset, char *name */ );
+extern	void charsetinit	( /* struct charsetproc *charset, char *name */ );
 
 /*
  * Initialise the stack, starting with a character set processor with
  * a particular name.
  */
-extern	charsetnameinit	( /* char *name */ );
+extern	void charsetnameinit	( /* char *name */ );
 
 /*
  * Push a new character set processor onto the stack.
  */
-extern	charsetpush	( /* struct charsetproc *charset */ );
+extern	void charsetpush	( /* struct charsetproc *charset */ );
 
 /*
  * Pop the top-most character set processor off the stack
  * if it matches the given processor.  Note: the base
  * processor is never popped off.
  */
-extern	charsetpop	( /* struct charsetproc *charset */ );
+extern	void charsetpop	( /* struct charsetproc *charset */ );
 
 /*
  * See if the character set processor on the top of the stack
@@ -119,18 +119,18 @@ extern	int	charsettop ( /* struct charse
  * Set the details for a character set member in the top-most
  * character set.
  */
-extern	charmember	( /* struct charsetmember *member, RCHAR ch */ );
+extern	void charmember	( /* struct charsetmember *member, RCHAR ch */ );
 
 /*
  * Set the details for a member of a specific character set.
  */
-extern	charmemberspec	( /* struct charsetmember *member, RCHAR ch,
+extern	void charmemberspec	( /* struct charsetmember *member, RCHAR ch,
 			     struct charset *charset */ );
 
 /*
  * Set the details for a output control code character.
  */
-extern	charmemberctrl	( /* struct charsetmember *member, RCHAR ch */ );
+extern	void charmemberctrl	( /* struct charsetmember *member, RCHAR ch */ );
 
 /*
  * Determine if the given character is a control code character.
