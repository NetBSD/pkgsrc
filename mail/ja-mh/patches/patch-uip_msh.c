$NetBSD: patch-uip_msh.c,v 1.1 2013/03/28 21:31:26 joerg Exp $

--- uip/msh.c.orig	2013-03-28 18:19:47.000000000 +0000
+++ uip/msh.c
@@ -181,6 +181,23 @@ jmp_buf sigenv;			/* the environment poi
 
 static TYPESIG	intrser (), pipeser (), quitser ();
 
+void readids (int id);
+void display_info (int scansw);
+void filecmd (char **args);
+void foldcmd (char **args);
+void explcmd (char **args);
+void forwcmd (char **args);
+void markcmd (char **args);
+void mhncmd (char **args);
+void packcmd (char **args);
+void distcmd (char **args);
+void pickcmd (char **args);
+void replcmd (char **args);
+void showcmd (char **args);
+void scancmd (char **args);
+void rmmcmd (char **args);
+void sortcmd (char **args);
+void forkcmd (char **args, char *pgm);
 
 #ifndef	__STDC__
 #ifdef	SYS5
@@ -189,10 +206,14 @@ struct passwd  *getpwnam ();
 #endif
 
 static int	read_map(), read_file(), check_folder(), getargs(), parse();
-static int	getcmds(), init_io(), initaux_io(), finaux_io(), peerwait();
+static int	getcmds(), init_io(), initaux_io(), peerwait();
+static void finaux_io (struct Cmd *cmdp);
 static int	pINI(), pQRY(), pQRY1(), pQRY2(), pCMD(), pFIN();
 static int	ttyR(), ttyNaux(), winN(), winR(), winX();
-static		msh(), m_gMsgs(), scanrange(), scanstring(), quit();
+static		scanrange(), scanstring();
+static void msh (int scansw);
+static void m_gMsgs (int n);
+static void quit(void);
 static		fin_io(), m_init();
 #if defined(BPOP) || defined(NNTP)
 static int	read_pop();
@@ -461,8 +482,7 @@ static struct swit mshcmds[] = {
 
 /*  */
 
-static  msh (scansw)
-int     scansw;
+static void msh (int scansw)
 {
     int     i;
     register char  *cp,
@@ -924,8 +944,7 @@ register char  *s;
 
 /*  */
 
-static m_gMsgs (n)
-int	n;
+static void m_gMsgs (int n)
 {
     int	    nmsgs;
 
@@ -1184,8 +1203,7 @@ char   *arg;
 
 /*  */
 
-readids (id)
-int     id;
+void readids (int id)
 {
     register int    cur,
                     flags,
@@ -1284,8 +1302,7 @@ int     msgnum;
 
 /*  */
 
-display_info (scansw)
-int     scansw;
+void display_info (int scansw)
 {
     int     flags,
             sd;
@@ -1332,7 +1349,7 @@ int     scansw;
 
 /*  */
 
-static	write_ids () {
+static void write_ids (void) {
     int     i = 0,
 	    flags,
             msgnum;
@@ -1358,7 +1375,7 @@ static	write_ids () {
 
 /*  */
 
-static  quit () {
+static void quit (void) {
     int     i,
             md,
             msgnum;
@@ -1945,8 +1962,7 @@ int	vio;
 }
 
 
-static int  finaux_io (cmdp)
-register struct Cmd *cmdp;
+static void finaux_io (struct Cmd *cmdp)
 {
     switch (cmdp -> direction) {
 	case STDIO: 
