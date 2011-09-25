$NetBSD: patch-prof.c,v 1.1 2011/09/25 19:53:55 joerg Exp $

--- prof.c.orig	2011-09-25 09:35:54.000000000 +0000
+++ prof.c
@@ -65,7 +65,7 @@ static 	 u_int		profInitFlag;
 /* local (internal) functions */
 static u_short copyfile(FILE *, FILE *, u_int);
 static u_short findOffset(FILE *, char *, u_short *);
-static u_short getline(FILE *, char *, u_short, u_short);
+static u_short my_getline(FILE *, char *, u_short, u_short);
 static u_short strcpymax(char *, char *, u_short);
 
 u_int profGetLine(u_short lineno, char *pLine, u_short maxline, char *pFile)
@@ -89,7 +89,7 @@ if ((fp = fopen(pFile, "r")) == NULL)
 
 ret = 0;
 while (lineno--)
-	ret = (u_int)getline(fp, pLine, maxline, PROF_TYPE_PLAIN);
+	ret = (u_int)my_getline(fp, pLine, maxline, PROF_TYPE_PLAIN);
 
 fclose(fp);
 
@@ -169,7 +169,7 @@ if ((fp = fopen(pFile,"r")) == NULL)
 
 cnt = 1;
 while (cnt != 0)
-	if ((cnt = getline(fp, achLine, sizeof(achLine),PROF_TYPE_CONF)) != 0)
+	if ((cnt = my_getline(fp, achLine, sizeof(achLine),PROF_TYPE_CONF)) != 0)
 		{
 		ptr = strtok(achLine, "=");
 
@@ -372,7 +372,7 @@ pDest[len] = '\0';
 return (len);
 }
 
-static u_short getline(FILE *fp, char *pBuffer, u_short usBuflen, u_short type)
+static u_short my_getline(FILE *fp, char *pBuffer, u_short usBuflen, u_short type)
 {
 int	ch;
 u_short	cnt;
