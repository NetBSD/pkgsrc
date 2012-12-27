$NetBSD: patch-src_rt_devcomm.c,v 1.1 2012/12/27 00:23:21 dholland Exp $

Pass around input buffer lengths.

--- src/rt/devcomm.c~	2004-10-01 07:43:05.000000000 +0000
+++ src/rt/devcomm.c
@@ -24,7 +24,7 @@ FILE	*devin, *devout;
 int	devchild;
 
 static struct driver * final_connect(void);
-static void mygets(char	*s, FILE	*fp);
+static void mygets(char	*s, size_t, FILE	*fp);
 static void myputs(char	*s, FILE	*fp);
 static void reply_error(char	*routine);
 static void getstate(void);
@@ -223,6 +223,7 @@ comm_comout(			/* print string to comman
 static void
 comm_comin(			/* read string from command line */
 	char	*buf,
+	size_t	max,
 	char	*prompt
 )
 {
@@ -236,7 +237,7 @@ comm_comin(			/* read string from comman
 	fflush(devout);
 	if (getc(devin) != COM_COMIN)
 		reply_error("comin");
-	mygets(buf, devin);
+	mygets(buf, max, devin);
 	getstate();
 }
 
@@ -244,15 +245,20 @@ comm_comin(			/* read string from comman
 static void
 mygets(				/* get string from file (with nul) */
 	register char	*s,
-	register FILE	*fp
+	size_t max,
+	FILE *fp
 )
 {
 	register int	c;
+	size_t pos = 0;
 
-	while ((c = getc(fp)) != EOF)
-		if ((*s++ = c) == '\0')
+	while ((c = getc(fp)) != EOF) {
+		if (pos >= max - 1)
+			break;
+		if ((s[pos++] = c) == '\0')
 			return;
+	}
-	*s = '\0';
+	s[pos] = '\0';
 }
 
 
