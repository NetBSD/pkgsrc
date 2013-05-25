$NetBSD: patch-correct.c,v 1.1 2013/05/25 23:46:51 joerg Exp $

--- correct.c.orig	2013-05-25 18:03:03.000000000 +0000
+++ correct.c
@@ -245,7 +245,7 @@ static void	save_root_cap P ((ichar_t * 
 		  struct flagent * sufent,
 		  ichar_t savearea[MAX_CAPS][INPUTWORDLEN + MAXAFFIXLEN],
 		  int * nsaved));
-static char *	getline P ((char * buf, int bufsize));
+static char *	my_getline P ((char * buf, int bufsize));
 void		askmode P ((void));
 void		copyout P ((unsigned char ** cc, int cnt));
 static void	lookharder P ((unsigned char * string));
@@ -571,7 +571,7 @@ checkagain:
 
 		imove (li - 1, 0);
 		(void) putchar ('!');
-		if (getline ((char *) buf, sizeof buf) == NULL)
+		if (my_getline ((char *) buf, sizeof buf) == NULL)
 		    {
 		    (void) putchar (7);
 		    ierase ();
@@ -596,7 +596,7 @@ checkagain:
 		    (void) printf ("%s ", CORR_C_READONLY);
 		    }
 		(void) printf (CORR_C_REPLACE_WITH);
-		if (getline ((char *) ctok, ctokl) == NULL)
+		if (my_getline ((char *) ctok, ctokl) == NULL)
 		    {
 		    (void) putchar (7);
 		    /* Put it back */
@@ -664,7 +664,7 @@ checkagain:
 		unsigned char	buf[100];
 		imove (li - 1, 0);
 		(void) printf (CORR_C_LOOKUP_PROMPT);
-		if (getline ((char *) buf, sizeof buf) == NULL)
+		if (my_getline ((char *) buf, sizeof buf) == NULL)
 		    {
 		    (void) putchar (7);
 		    ierase ();
@@ -1583,7 +1583,7 @@ static void save_root_cap (word, pattern
     return;
     }
 
-static char * getline (s, len)
+static char * my_getline (s, len)
     register char *	s;
     register int	len;
     {
