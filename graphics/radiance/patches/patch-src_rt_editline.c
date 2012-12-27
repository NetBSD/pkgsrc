$NetBSD: patch-src_rt_editline.c,v 1.1 2012/12/27 00:23:21 dholland Exp $

Pass around (and honor) input buffer lengths.

--- src/rt/editline.c~	2004-04-10 02:54:09.000000000 +0000
+++ src/rt/editline.c
@@ -26,13 +26,14 @@ static const char	RCSid[] = "$Id: editli
 extern void
 editline(	/* edit input line */
 	char  *buf,
+	size_t bufmax,
 	dr_getchf_t *c_get,
 	dr_comoutf_t *s_put
 )
 {
 	static char  erases[] = "\b \b";
 	static char  obuf[4];
-	register int  i;
+	register size_t  i;
 	register int  c;
 	
 	i = 0;
@@ -62,6 +63,8 @@ editline(	/* edit input line */
 			obuf[0] = '^'; obuf[1] = c|0100; obuf[2] = '\0';
 			(*s_put)(obuf);
 			break;
+		} else if (i >= bufmax - 1) {		/* overflow */
+			(*s_put)("\a");
 		} else {				/* regular char */
 			buf[i++] = c;
 			obuf[0] = c; obuf[1] = '\0';
@@ -98,16 +101,22 @@ register struct driver  *d;
 
 
 int
-fromcombuf(b, d)			/* get command from my buffer */
+fromcombuf(b, max, d)			/* get command from my buffer */
 char  *b;
+size_t max;
 struct driver  *d;
 {
-	register char	*cp;
+	char	*cp;
+	size_t pos;
 						/* get next command */
-	for (cp = mybuf; *cp != '\n'; cp++)
-		if (!*cp)
+	for (pos = 0; mybuf[pos] != '\n' && pos < max - 1; pos++)
+		if (!mybuf[pos])
 			return(0);
-	*cp++ = '\0';
+	/*
+	 * On overflow this loses a character, but it isn't supposed
+	 * to overflow.
+	 */
+	mybuf[pos++] = '\0';
 #ifdef DEBUG
 	(*d->comout)(mybuf);			/* echo my command */
 	(*d->comout)("\n");
