$NetBSD: patch-uip_post.c,v 1.1 2013/03/28 21:31:26 joerg Exp $

--- uip/post.c.orig	2013-03-28 18:44:13.000000000 +0000
+++ uip/post.c
@@ -365,10 +365,24 @@ static	char   *record = NULLCP;
 off_t	lseek ();
 time_t	time ();
 
-static	putfmt(), start_headers(), finish_headers(), putgrp(), pl();
+#ifndef	MHMTS
+static void do_addresses (int bccque, int talk);
+#else	/* MHMTS */
+static void do_addresses (char *file, int fd, int ud, int bccque, int talk);
+#endif	/* MHMTS */
+
+static	start_headers(), finish_headers(), pl();
+static void putfmt (char *name, char *str, FILE *out);
+static void putgrp (char *name, char *group, FILE *out, unsigned int flags);
 static	anno(), make_bcc_file(), verify_all_addresses();
-static	chkadr(), do_addresses(), do_text(), do_an_address(), sigon();
-static 	sigoff(), p_refile(), fcc(), die(), insert_fcc(), p_record ();
+static	chkadr(), do_text();
+static void do_an_address (struct mailname *lp, int talk, int tma);
+static void sigon (void);
+static 	fcc(), die();
+static void insert_fcc (struct headers *hdr, char *pp);
+static void sigoff (void );
+static void p_refile (char *file);
+static void p_record (void);
 static int	get_header(), putadr(), insert(), annoaux();
 #ifdef TMA
 static	postplain();
@@ -844,10 +858,7 @@ daemon: ;
 
 /*    DRAFT GENERATION */
 
-static putfmt (name, str, out)
-register char   *name,
-		*str;
-register FILE *out;
+static void putfmt (char *name, char *str, FILE *out)
 {
     int     count,
             grp,
@@ -1264,11 +1275,7 @@ unsigned int    flags;
 
 /*  */
 
-static putgrp (name, group, out, flags)
-register char   *name,
-		*group;
-register FILE *out;
-unsigned int    flags;
+static void putgrp (char *name, char *group, FILE *out, unsigned int flags)
 {
     int     len;
     char   *cp;
@@ -1418,9 +1425,7 @@ register struct mailname *mp;
 
 /*  */
 
-static  insert_fcc (hdr, pp)
-register struct	headers *hdr;
-register char   *pp;
+static void insert_fcc (struct headers *hdr, char *pp)
 {
     register char   *cp;
 
@@ -1952,15 +1957,10 @@ int	talk;
 /*  */
 
 #ifndef	MHMTS
-static do_addresses (bccque, talk)
+static void do_addresses (int bccque, int talk)
 #else	/* MHMTS */
-static do_addresses (file, fd, ud, bccque, talk)
-register char   *file;
-int	fd,
-	ud;
+static void do_addresses (char *file, int fd, int ud, int bccque, int talk)
 #endif	/* MHMTS */
-int	bccque,
-	talk;
 {
     int     retval;
 #ifndef	BERK
@@ -2122,10 +2122,7 @@ int     fd;
 /* ARGSUSED */
 #endif	/* TMA */
 
-static do_an_address (lp, talk, tma)
-register struct mailname *lp;
-int     talk,
-	tma;
+static void do_an_address (struct mailname *lp, int talk, int tma)
 {
     int     len,
             retval;
@@ -2260,10 +2257,7 @@ int     talk,
 #ifdef	MHMTS
 /* ARGSUSED */
 
-static do_an_address (lp, talk, tma)
-register struct mailname *lp;
-int     talk,
-	tma;
+static void do_an_address (struct mailname *lp, int talk, int tma)
 {
     register char  *mbox;
     char    addr[BUFSIZ];
@@ -2353,10 +2347,7 @@ int     talk,
 /* ARGSUSED */
 #endif	/* TMA */
 
-static do_an_address (lp, talk, tma)
-register struct mailname *lp;
-int     talk,
-	tma;
+static void do_an_address (struct mailname *lp, int talk, int tma)
 {
     int     retval;
     register char  *mbox,
@@ -2463,7 +2454,7 @@ int     i;
 #endif	/* not MHMTS */
 
 
-static  sigon () {
+static void sigon (void) {
     if (debug)
 	return;
 
@@ -2481,7 +2472,7 @@ static  sigon () {
 }
 
 
-static sigoff () {
+static void sigoff (void ) {
     if (debug)
 	return;
 
@@ -2493,8 +2484,7 @@ static sigoff () {
 
 /*    FCC INTERACTION */
 
-static  p_refile (file)
-register char   *file;
+static void p_refile (char *file)
 {
     register int     i;
 
@@ -2560,7 +2550,7 @@ register char   *file,
 
 /*    RECORD RECIPIENTS */
 
-static	p_record ()
+static void p_record (void)
 {
     int	    i,
 	    child_id,
